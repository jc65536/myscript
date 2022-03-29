#include <stdbool.h>
#include <stdlib.h>

#include "string-parse.h"

int read_token(char *it, token *t) {
    while (*it == ' ')
        it++;

    if (!*it)
        return 1;

    char terminator = ' ';

    t->begin = it;

    if (*it == '"') {
        t->type = STRING_TOKEN;
        t->begin++;
        terminator = '"';
    } else if (*it == '.') {
        t->type = FLOAT_TOKEN;
    } else if ('0' <= *it && *it <= '9') {
        t->type = INT_TOKEN;
    } else if ('a' <= *it && *it <= 'z' || *it == '_') {
        t->type = WORD_TOKEN;
    } else {
        return 2;
    }
    it++;

    // Escape only applies for strings
    bool esc = false;
    int esc_offset = 0;

    while (*it && (esc || *it != terminator)) {
        switch (t->type) {
        case INT_TOKEN:
            if (*it == '.') {
                t->type = FLOAT_TOKEN;
                break;
            }
            // Fall through
        case FLOAT_TOKEN:
            if (*it < '0' || *it > '9')
                return 2;
            break;
        case STRING_TOKEN:
            if (!esc && *it == '\\') {
                esc = true;
                esc_offset++;
            } else {
                esc = false;
                *(it - esc_offset) = *it;
            }
            break;
        }
        it++;
    }

    t->len = it - t->begin - esc_offset;

    // A single . can't be a float
    if (t->type == FLOAT_TOKEN && t->len == 1)
        return 2;
    
    t->end = *it ? ++it : it; // Don't increment past the end of the string
    *(t->begin + t->len) = '\0';
    return 0;
}
