#include <stdio.h>
#include <stdlib.h>

int ifVowel(char c) {
	const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
	
	for (int i = 0; i < 5; i++) {
		if (c == vowels[i]) {
			return 1;
		}
	}
	
	return 0;
	
}

int checkString(char *currPointer, char *prevPointer, int *doubleIncrem) {
	//char forbiddenDouble = {"ab", "cd", "pq", "xy"};
	
	if (*prevPointer == *currPointer) {
		(*doubleIncrem)++;
	}
	
	if (
	(*prevPointer == 'a' && *currPointer == 'b') ||
	(*prevPointer == 'c' && *currPointer == 'd') ||
	(*prevPointer == 'p' && *currPointer == 'q') ||
	(*prevPointer == 'x' && *currPointer == 'y')) {
		return 1;
	} else {
		return 0;
	}
	
}

int checkNice(char *stream) {
	int vowelCount = 0;
	int doubleCount = 0;
	
	int i = 0;
	
	// p1 is current char. p2 is prev char.
	char *p1, *p2;
	//int forbidden = 0;
	
	p1 = &stream[0];
	p2 = &stream[1];
	
	if (ifVowel(*p1)) {
		vowelCount++;
	}
		
	while (*p2 != '\0') {
		
		if (ifVowel(*p2)) {
			vowelCount++;
		}
		
		if (checkString(p2, p1, &doubleCount)) {
			//forbidden = 1;
			return 0;
		}
		
		// DEBUG.
		//fprintf(stdout, "Vowel: %d Double: %d Letters: %c %c Forbidden: %d\n", vowelCount, doubleCount, *p1, *p2, forbidden);
				
		p1++;
		p2++;
		
	}
	
	if (vowelCount >= 3 && doubleCount) {
		return 1;
	} else {
		return 0;
	}
		
}

// Checks for repeated letters spaced by a single letter.
int singleLetterRepeat(char *currentPointer) {
	if (*currentPointer == *(currentPointer + 2) && *(currentPointer + 1) != '\0') {
		return 1;
	} else {
		return 0;
	}
}

// Checks for any pair in new rules.
int checkPair(char *pointer, char *stream) {
	char pair[2];
	// {0, 1, 2, 3}
	char *scanPointer;
	scanPointer	= pointer + 2;
	
	pair[0] = *pointer;
	pair[1] = *(pointer + 1);
	
	while (*scanPointer != '\0') {
		if (*scanPointer == pair[0] && *(scanPointer + 1) == pair[1]) {
			return 1;
		}
		
		scanPointer++;
	}
	
	return 0;
	
}

// Checks whether string is naughty or nice using new rules.
// TODO: Special rule for p2 pair if p2 == \0.
int checkNiceNew(char *stream) {
	int pairFlag = 0;
	int repeatFlag = 0;
	
	char *pointer;
	pointer = &stream[0];
	
	while (*pointer != '\0') {
		
		if (singleLetterRepeat(pointer)) {
			repeatFlag = 1;
		}
		
		if (checkPair(pointer, stream)) {
			pairFlag = 1;
		}
		
		pointer++;
	}
	
	if (repeatFlag && pairFlag) {
		return 1;
	} else {
		return 0;
	}
	
}