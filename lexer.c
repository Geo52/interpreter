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
    UNKNOWN,
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
        token = tokenCreate(UNKNOWN, NULL);
        break;
    }
    return token;
}

int main()
{
    FILE *file;
    file = fopen("source.txt", "r");

    // loop through the source code one character at a time
    int characterInQuestion;
    while ((characterInQuestion = fgetc(file)) != EOF)
    {
        // ignore whitespace
        if (isspace(characterInQuestion))
        {
            continue;
        }

        Token token = tokenizer(characterInQuestion, token);

        printf("%c\n", characterInQuestion);

        printf("Token Type: %d  ", token.type);
        printf("Token literal: %s\n", token.literal);
    }
    fclose(file);
}