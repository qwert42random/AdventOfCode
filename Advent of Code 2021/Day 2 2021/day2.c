#include "day2.h"

int main() {
    FILE *inFile;
    signed int horizontal = 0;
    signed int vertical = 0;

    inFile = fopen("day2_input.txt", "r");

    calculatePosition(inFile, &horizontal, &vertical);

    fprintf(stdout, "Horizontal: %d\nVertical: %d\n", horizontal, vertical);
    fprintf(stdout, "Product: %d\n", horizontal * vertical);

}
