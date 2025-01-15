all: lexer

lexer: lexer.c
	gcc -o lexer lexer.c -g

clean:
	rm lexer