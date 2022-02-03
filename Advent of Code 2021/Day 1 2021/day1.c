#include "day1.h"

int main() {
	FILE *inFile;
	int *inputList;
	int inputSize;
	
	inFile = fopen("input.txt", "r");
	
	inputList = (int *) malloc(sizeof(int));
	
	if (inputList == NULL) {
		fprintf(stdout, "ERROR");
		return 0;
	}
		
	inputSize = parseInput(inFile, &inputList);
	
	
	fprintf(stdout, "Decrease Count: %d\n", countDecrease(inputList, inputSize));
	fprintf(stdout, "Decrease Count (with windows): %d\n", measureWindows(inputList, inputSize));
	free(inputList);
	
}