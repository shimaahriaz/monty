#include "monty.h"

void err(int error_code, ...) {
    va_list ag;
    va_start(ag, error_code);

    int l_num;
    char *op;

    switch (error_code) {
        case 1:
            fprintf(stderr, "USAGE: monty file\n");
            break;
        case 2:
            op = va_arg(ag, char *);
            fprintf(stderr, "Error: Can't open file %s\n", op);
            break;
        case 3:
            l_num = va_arg(ag, int);
            op = va_arg(ag, char *);
            fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
            break;
        case 4:
            fprintf(stderr, "Error: malloc failed\n");
            break;
        case 5:
            l_num = va_arg(ag, int);
            fprintf(stderr, "L%d: usage: push integer\n", l_num);
            break;
        default:
            break;
    }
