#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adv_math.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <add|sub> <a> <b>\n", argv[0]);
        return 1;
    }

    float a = atof(argv[2]);
    float b = atof(argv[3]);

    if (strcmp(argv[1], "add") == 0) {
        printf("Result: %f\n", advm_add(a, b));
    } else if (strcmp(argv[1], "sub") == 0) {
        printf("Result: %f\n", advm_sub(a, b));
    } else {
        printf("Unknown command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}