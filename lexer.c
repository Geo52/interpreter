#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum
{
    // Single-character tokens.
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,
} Token_Type;

typedef struct
{
    Token_Type type;
    char *literal;

} Token;

Token tokenCreate(Token_Type type, char *literal)
{
    Token token;
    token.type = type;
    token.literal = literal;
    return token;
}

Token tokenizer(char characterInQuestion, Token token)
{
    switch (characterInQuestion)
    {
    case '(':
        // when you find a token intialize it
        token = tokenCreate(LEFT_PAREN, NULL);
        break;
    case ')':
        token = tokenCreate(RIGHT_PAREN, NULL);
        break;
    case '{':
        token = tokenCreate(LEFT_BRACE, NULL);
        break;
    case '}':
        token = tokenCreate(RIGHT_BRACE, NULL);
        break;
    case ',':
        token = tokenCreate(COMMA, NULL);
        break;
    case '.':
        token = tokenCreate(DOT, NULL);
        break;
    case '-':
        token = tokenCreate(MINUS, NULL);
        break;
    case '+':
        token = tokenCreate(PLUS, NULL);
        break;
    case ';':
        token = tokenCreate(SEMICOLON, NULL);
        break;
    case '/':
        token = tokenCreate(SLASH, NULL);
        break;
    case '*':
        token = tokenCreate(STAR, NULL);
        break;
    default:
        break;
    }
    return token;
}

int main()
{
    FILE *file;
    file = fopen("source.txt", "r");
    char source_code[100];
    fgets(source_code, 100, file);

    // loop through the source code one character at a time
    for (int i = 0; source_code[i] != '\0'; i++)
    {
        // ignore whitespace
        if (isspace(source_code[i]))
        {
            continue;
        }

        Token token = tokenizer(source_code[i], token);

        printf("Token Type: %d  ", token.type);
        printf("Token literal: %s\n", token.literal);
    }
}