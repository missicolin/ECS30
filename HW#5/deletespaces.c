#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void flushStdin();

void removeSpaces(char* inputString) {
	char* i = inputString;
	char* j = inputString;
	while(*j != 0) {
		*i = *j++;
		if(*i != ' ')
			i++;
	}
	*i = 0;
}
int main() {
	int num;
	printf("Enter a max string length: ");
	scanf("%d", &num);
	flushStdin();
	
	char noSpaces[num + 1];

	printf("Enter the string to delete whitespace from: ");
	fgets(noSpaces, sizeof(noSpaces), stdin);	

	removeSpaces(noSpaces);
	printf("Result:\n");
	printf("%s" ,noSpaces);

	return 0;
}

void flushStdin() {
	char c;
	while ( (c = getchar()) != EOF && c!= '\n' && c != '\r') {};
}

