main: com/craftinginterpreters/lox/Lox.java
	javac com/craftinginterpreters/lox/Lox.java

watch:
	fd --glob *.java | entr -cr sh -c "make --no-print-directory && java com/craftinginterpreters/lox/Lox"

run:
	make --no-print-directory && java com/craftinginterpreters/lox/Lox
