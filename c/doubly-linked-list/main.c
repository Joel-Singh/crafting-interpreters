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
void printll(LinkedList* ll);

int main(void) {
  test_insertll();
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
