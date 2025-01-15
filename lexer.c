#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    // Single-character tokens
    PLUS,

    // One or two character tokens

    // Literals

    // Keywords



} Token_Type;

// define a token
typedef struct
{
    Token_Type type; 
    char value;
} Token;

int main()
{
    // hard coded example source code
    char source_code[] = "let x = 5 + 5;";


}