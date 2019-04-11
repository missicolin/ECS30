#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	int i, j, upper, lower, dif, dife, guess, numGuesses;
	double iniGuess;
	char user;

	printf("Enter n: ");
	scanf("%d", &upper);
	if (upper >= 2){
	}
	else if (upper < 0){
		printf("Error: n must be positive\n");
	return 0;
	}
	else if (upper < 2 || upper >= 0){
		printf("Your number must be 1. I used 0 guesses.\n");
	return 0;
	}
	else{
		printf("Error: invalid input\n");
	return 0;
	}
	
	lower  = 1;
	iniGuess = (double) upper / 2 + 0.5;
	guess = (int) iniGuess;
	printf("Is your number %d? ", guess);
	scanf(" %c", &user);
        i = 0;
	j = 0;
		
	while (user == 'l'){
         	guess = (int) (guess) + (0.5 * (upper - guess));
		printf("Is your number %d? ", guess);
        	scanf(" %c", &user);
		i++;
		numGuesses = i + j + 1;
		if (upper - guess == 1) {
			printf("Your number must be %d. I used %d guesses.", upper, numGuesses);
		return 0;
		}
		lower = guess - (upper - guess);
		dife = upper - guess;
		if(user == 's' && dife < 2) {
			printf("Error: that's not possible.\n");
		return 0;
		}
	        if(user == 's' && dife == 2){
			printf("Your number must be %d. I used %d guesses.\n", guess, numGuesses);
		return 0; }
	}
	while (user == 's'){
		guess =  (int) (guess) - 0.5 * (guess - lower);
		printf("Is your number %d? ", guess);
		scanf(" %c", &user);
		j++;
		numGuesses= i + j + 1;
		if(guess - lower == 1){
			printf("Your number must be %d. I used %d guesses.\n", lower, numGuesses);
		return 0; }
		upper = guess - (guess - lower);
		dif = guess - lower;
		if(user == 'l' && dif  < 2) {
			printf("Error: that's not possible.\n", dif);
		return 0;
		}
		if(user == 'l' && dif == 2) {
		       printf("Error: that's not possible.\n",dif);
	       return 0;
		}	       
		}
	while (user == 'e'){
		numGuesses = i + j + 1;
		printf("Your number must be %d. I used %d guesses.\n", guess, numGuesses);
		return 0;
		}
	if (user != 'l' || user != 's' || user != 'e'){
		printf("Error: invalid input.\n");
		return 0;
		}
	
	return 0;
}


