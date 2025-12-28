/*
* A doubly linked list implementation in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
* The linked list will be a struct with:
*   Head
*   Tail
*/

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node {
  Node* next;
  Node* prev;
  int* data;
};

struct LinkedList {
  Node* head;
  Node* tail;
};

void insertll(LinkedList* ll, int data, int index);
void test_insertll();

void deletell(LinkedList* ll, int index);
void test_deletell();

void printll(LinkedList* ll);

int main(void) {
  test_deletell();
}

void insertll(LinkedList* ll, int data, int index) {
  if (index < 0) {
    printf("Invalid index < 0 for linked list! Index: %d", index);
    exit(EXIT_FAILURE);
  }

  Node* p = NULL;
  Node* n = ll->head;

  for (int i = 0; i < index; i++) {
    if (n == NULL) {
      printf("Invalid too big index for linked list of length %d! Index: %d", i, index);
      exit(EXIT_FAILURE);
    }

    n = n->next;
  }

  if (n != NULL) {
    p = n->prev;
  } else {
    // If n is null, that means index == length and the previous element will be the tail
    p = ll->tail;
  }

  Node* x = malloc(sizeof(Node));
  x->next = NULL;
  x->prev = NULL;
  x->data = malloc(sizeof(int));
  *x->data = data;

  // Empty linked list
  if (p == NULL && n == NULL) {
    ll->head = x;
    ll->tail = x;
  } else if (n == NULL) {
    ll->tail = x;
    p->next = x;
    x->prev = p;
  } else if (p == NULL) {
    ll->head = x;
    n->prev = x;
    x->next = n;
  } else {
    p->next = x;
    n->prev = x;

    x->next = n;
    x->prev = p;
  }
}

void deletell(LinkedList* ll, int index) {
  if (index < 0) {
    printf("Invalid index < 0 for linked list! Index: %d", index);
    exit(EXIT_FAILURE);
  }

  Node* x = ll->head;

  for (int i = 0; i < index; i++) {
    if (x == NULL) {
      printf("Invalid too big index for linked list of length %d! Index: %d", i, index);
      exit(EXIT_FAILURE);
    }

    x = x->next;
  }

  if (x == NULL) {
    printf("Trying to delete from empty list!");
    exit(EXIT_FAILURE);
  }

  if (x == ll->head) {
    ll->head = x->next;
  }

  if (x == ll->tail) {
    ll->tail = x->prev;
  }

  if (x->next != NULL) {
    x->next->prev = x->prev;
  }

  if (x->prev != NULL) {
    x->prev->next = x->next;
  }

  free(x->data);
  free(x);
}

void printll(LinkedList* ll) {
  printf("NULL");

  for(Node* n = ll->head; n != NULL; n = n->next) {
    assert(n != n->next);
    printf("<->%d", *n->data);
  }

  printf("<->NULL\n");
}

void test_insertll() {
  LinkedList ll = {.head = NULL, .tail = NULL};
  printll(&ll);

  insertll(&ll, 0, 0);
  printll(&ll);

  insertll(&ll, 1, 0);
  printll(&ll);

  insertll(&ll, 2, 2);
  printll(&ll);

  insertll(&ll, 3, 2);
  printll(&ll);
}

void test_deletell() {
  LinkedList ll = {.head = NULL, .tail = NULL};

  insertll(&ll, 4, 0);
  insertll(&ll, 3, 0);
  insertll(&ll, 2, 0);
  insertll(&ll, 1, 0);

  printll(&ll);

  deletell(&ll, 0);
  printll(&ll);

  deletell(&ll, 1);
  printll(&ll);

  deletell(&ll, 1);
  printll(&ll);

  deletell(&ll, 0);
  printll(&ll);
}
