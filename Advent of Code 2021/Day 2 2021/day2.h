#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculatePosition(FILE *inputFile, int *horizontal, int *vertical) {
    char position[10];
    int distance;
    int compare;

    while (fscanf(inputFile, "%s %d\n", &position, &distance) != EOF) {

        if (!strcmp(position, "forward")) {
            *horizontal += distance;
        } else if (!strcmp(position, "up")) {
            *vertical -= distance;
        } else {
            *vertical += distance;
        }
    }

}
