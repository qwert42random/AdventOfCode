#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long returnSmallest(long sides[3]) {
	long smallest = sides[0];
	
	for (int ii = 1; ii <= 2; ii++) {
		if (sides[ii] < smallest) {
			smallest = sides[ii];
		}
	}
	
	return smallest;
	
}

long *parseInput(char *stream, long sideArray[3]) {
	
	int j = 0;
	
	char *token;
	
	token = strtok(stream, "x");
		
	while (token != NULL) {
		sideArray[j] = strtol(token, NULL, 10);
		token = strtok(NULL, "x");
		j++;
	}
	
	//fprintf(stdout, "%-- ld %ld %ld --", sideArray[0], sideArray[1], sideArray[2]);
	
	return sideArray;
	
}

long calcPaper(long dimensions[3]) {
	
	long side1 = dimensions[0] * dimensions[1];
	long side2 = dimensions[1] * dimensions[2];
	long side3 = dimensions[2] * dimensions[0];
	
	long sideArray[3] = {side1, side2, side3};
	
	return 2 * side1 + 2 * side2 + 2 * side3 + returnSmallest(sideArray);
	
}

long calcRibbon(long sides[3]) {
	// Find largest. Return the smaller two remaining.
	int largestIndex = 0;
	long totalSides = sides[0] * sides[1] * sides[2];
	
	for (int i = 0; i < 3; i++) {
		if (sides[i] > sides[largestIndex]) {
			largestIndex = i;
		}
	}
	
	switch (largestIndex) {
		case 0:
			return sides[1] * 2 + sides[2] * 2 + totalSides;
			break;
		case 1:
			return sides[0] * 2 + sides[2] * 2 + totalSides;
			break;
		case 2:
			return sides[0] * 2 + sides[1] * 2 + totalSides;
			break;
	}
	
}

void main() {
	FILE *inFile;
	int i;
	long totalPaper = 0;
	long totalRibbon = 0;
	long presentDimensions[3];
	
	char c;
	char *stream;
	stream = (char *)malloc(sizeof(char));
	
	inFile = fopen("input2.txt", "r");
	
	c = fgetc(inFile);
	
	while (c != EOF) {
		
		i = 0;
		
		while (c != EOF || c != '\n') {
			stream = (char *)realloc(stream, i + 1);
			stream[i] = c;
			i++;
			c = fgetc(inFile);
			
			if (c == EOF || c == '\n') {
				break;
			}
			
		}
		stream = (char *) realloc(stream, i + 1);
		stream[i] = '\0';
				
		parseInput(stream, presentDimensions);
		
		totalPaper += calcPaper(presentDimensions);
		totalRibbon += calcRibbon(presentDimensions);
		
	}
	
	free(stream);
	
	fprintf(stdout, "Total Paper: %ld\n", totalPaper);
	fprintf(stdout, "Total Ribbon: %ld\n", totalRibbon);
	
	return;
	
}