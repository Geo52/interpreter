all: lexer

lexer: lexer.c
	gcc -o lexer lexer.c -g -Wall

clean:
	rm lexer