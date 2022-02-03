#include "day5.h"

void main() {
	FILE *inFile;
	char stream[20];
	int totalNice = 0;
	int totalNiceNew = 0;
		
	inFile = fopen("day5_testInput.txt", "r");
	
	
	while (fscanf(inFile, "%s\n", stream) != EOF) {
		totalNice += checkNice(stream);
		totalNiceNew += checkNiceNew(stream);
	}
	
	fprintf(stdout, "Total Nice Strings: %d\n", totalNice);
	fprintf(stdout, "Total Nice Strings (with new rule): %d\n", totalNiceNew);
	
	return;
	
}
