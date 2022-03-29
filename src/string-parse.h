#ifndef STRING_PARSE_H
#define STRING_PARSE_H

#define WORD_TOKEN 1
#define STRING_TOKEN 2
#define INT_TOKEN 3
#define FLOAT_TOKEN 4

typedef struct token {
    int type;
    char *begin;
    int len;
    char *end;
} token;

/*
Return status
0   Success
1   End of string reached
2   Ill-formed token
*/
int read_token(char *start, token *t);

#endif // Include guard
