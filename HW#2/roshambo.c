#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	char userChoice, r, p, s; 
	int computer;

	printf("Rock, paper, or scissors? ");
	scanf("%c", &userChoice);
	r = (userChoice == 'r');
	p = (userChoice == 'p');
	s = (userChoice == 's');

	srand((int)time(0));
	computer = rand() % 10 + 1;

//Rock	
	if (r && computer <= 3)
	{
		printf("I rolled rock. We tie!\n");
	}
	if ( p && computer <= 3) 
	{
		printf("I rolled rock. You win!\n");
	}
	if( s && computer <=3)
	{
		printf("I rolled rock. You lose!\n");
	}

//Paper
	if ( r && computer > 3 && computer <=6)
	{
		printf("I rolled paper. You lose!\n");
	}
	if ( p && computer > 3 && computer <= 6) 
	{
		printf("I rolled paper. We tie!\n");
	}
	if ( s && computer > 3 && computer <= 6)
	{
		printf("I rolled paper. You win!\n");
	}
//Scissors
	if ( r && computer >= 7)
	{
		printf("I rolled scissors. You win!\n");
	}
	if ( p && computer >= 7)
	{
		printf("I rolled scissors. You lose!\n");
	}
	if ( s && computer >= 7)
	{
		printf("I rolled scissors. We tie!\n");
	}
	if ( r || p || s) {
	}
	else {
		printf("Error: you did not enter 'r', 'p', or 's'!");
	}
	return 0;
}







