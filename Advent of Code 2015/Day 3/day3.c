#include <stdio.h>
#include <stdlib.h>

int calcCoords(FILE *input) {
	int totalHouses = 1;
	
	int *visitedCoordinates;
	int houseFound;
	
	visitedCoordinates = malloc(sizeof(int) * 2);
	visitedCoordinates[0] = 0;
	visitedCoordinates[1] = 0;
		
	char c = fgetc(input);
	
	signed int xCoord = 0;
	signed int yCoord = 0;
	
		
	while (c != EOF) {
		
		houseFound = 0;
		//shouseCoordinate = (int *)realloc(houseCoordinate, sizeof(int) * totalHouses);
		
		
		switch(c) {
			case '<':
				xCoord--;
				break;
			case '>':
				xCoord++;
				break;
			case '^':
				yCoord++;
				break;
			case 'v':
				yCoord--;
				break;
		}
		
		// Check if in list of previous coordinates.
		for (int i = 0; i < totalHouses; i++) {
			if (xCoord == visitedCoordinates[i * 2] && yCoord == visitedCoordinates[i * 2 + 1]) {
				houseFound = 1;
				break;
			}
		}
		
		// House was in the list.
		if (!houseFound) {
			totalHouses++;
			visitedCoordinates = (int *) realloc(visitedCoordinates, sizeof(int) * totalHouses * 2);
			visitedCoordinates[(totalHouses - 1) * 2] = xCoord;
			visitedCoordinates[totalHouses * 2 - 1] = yCoord;
		}
		
		c = fgetc(input);
		
	}
	
	free(visitedCoordinates);
	
	return totalHouses;
}

int calcCoordsRobo(FILE *input) {
	int totalHouses = 1;
	int index = 0;
	
	int *visitedCoordinates;
	int *xPointer, *yPointer;
	int houseFound;
	
	visitedCoordinates = malloc(sizeof(int) * 2);
	visitedCoordinates[0] = 0;
	visitedCoordinates[1] = 0;
		
	char c = fgetc(input);
	
	signed int xSanta = 0;
	signed int ySanta = 0;
	signed int xRobo = 0;
	signed int yRobo = 0;
	
	while (c != EOF) {
		
		houseFound = 0;
		
		if (index % 2 == 0) {
			xPointer = &xSanta;
			yPointer = &ySanta;
		} else {
			xPointer = &xRobo;
			yPointer = &yRobo;
		}
		
		switch(c) {
			case '<':
				(*xPointer)--;
				break;
			case '>':
				(*xPointer)++;
				break;
			case '^':
				(*yPointer)++;
				break;
			case 'v':
				(*yPointer)--;
				break;
		}
		
		// Check if in list of previous coordinates.
		for (int i = 0; i < totalHouses; i++) {
			if (*xPointer == visitedCoordinates[i * 2] && *yPointer == visitedCoordinates[i * 2 + 1]) {
				houseFound = 1;
				break;
			}
		}
		
		// House was not in the list (new house).
		if (!houseFound) {
			totalHouses++;
			visitedCoordinates = (int *) realloc(visitedCoordinates, sizeof(int) * totalHouses * 2);
			visitedCoordinates[(totalHouses - 1) * 2] = *xPointer;
			visitedCoordinates[totalHouses * 2 - 1] = *yPointer;
		}
		
		index++;
		c = fgetc(input);
		
	}
	
	return totalHouses;
}

int main() {
	FILE *inFile;
	int visited;
	int visitedRobo;
	
	inFile = fopen("day3_input.txt", "r");
	
	visited = calcCoords(inFile);
	rewind(inFile);
	visitedRobo = calcCoordsRobo(inFile);
	fclose(inFile);
	
	fprintf(stdout, "Visited (without RoboSanta): %d\n", visited);
	fprintf(stdout, "Visited (using RoboSanta): %d", visitedRobo);
	
	return 0;
	
}