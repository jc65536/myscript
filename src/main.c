#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "string-parse.h"

#define MAX_LINE_LEN 256

int main(int argc, char **argv) {
    FILE *file;
    if (argc < 2) {
        file = stdin;
    } else {
        file = fopen(argv[1], "r");

        if (!file) {
            printf("Error: Couldn't open file\n");
            return 1;
        }
    }

    char line[MAX_LINE_LEN];
    token t;
    while (fgets(line, MAX_LINE_LEN, file)) {
        line[strcspn(line, "\n")] = '\0';
        printf("LINE: <%s>\n", line);
        char *it = line;
        while (read_token(it, &t) == 0) {

            switch (t.type) {
            }

            it = t.end;
        }
    }
}
