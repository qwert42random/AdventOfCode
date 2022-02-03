#include <stdio.h>
#include <stdlib.h>

// This function here: the list of inputs.
int parseInput(FILE *inputFile, int **listOfInput) {
	
	int size = 0;
	int input;
	
	while (fscanf(inputFile, "%d\n", &input) != EOF) {
		*listOfInput = (int *) realloc(*listOfInput, sizeof(int) * (size + 1));
		(*listOfInput)[size] = input;
		size++;
	}
	
	return size;
}

// Count the number of decreases.
int countDecrease(int *inputList, int inputSize) {
	int prev, curr;
	int decreaseCount = 0;
	
	prev = inputList[0];
	
	for (int i = 1; i < inputSize; i++) {
		
		curr = inputList[i];
		
		if (curr > prev) {
			decreaseCount++;
		}
		
		prev = curr;
		
	}
	
	return decreaseCount;
}

// Measure windows for the second part and find number of decreases.
int measureWindows(int *inputList, int inputSize) {
	int prev, curr;
	int decreaseCount;
	int *windowSum;

	windowSum = (int *)malloc(sizeof(int) * (inputSize - 2));
	
	
	for (int i = 2; i < inputSize; i++) {
		windowSum[i - 2] = inputList[i] + inputList[i - 1] + inputList[i - 2];
	}
	
	decreaseCount = countDecrease(windowSum, inputSize - 2);
	free(windowSum);
	
	return decreaseCount;
}
