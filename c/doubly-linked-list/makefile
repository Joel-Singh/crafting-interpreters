main: main.c
	gcc main.c -o main.bin

watch:
	find ./ | entr -c sh -c "make --no-print-directory && ./main.bin"
