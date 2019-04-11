#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Constants used throughout the program.
// This would allow us to easily change the game to use, say, 4 dice instead of 5
#define NUM_DICE 5
#define NUM_FACES 6
#define UNSCORED_CATEGORY -1

// Sets up the game. Seed rand and mark every category as unscored
void initializeGame(int categoryScores[NUM_FACES]);

// Marks all die as unsaved. Used at the start of a round
void resetsavedDice(bool savedDice[NUM_DICE]);

// Play one round of simple yahtzee
void playRound(bool savedDice[NUM_DICE], int dice[NUM_DICE]);

// Obtains saved dice from player
void getPlayerSaveDice(bool savedDice[]);

// Re-roll all die that are not saved
void rollAllUnsavedDice(bool savedDice[NUM_DICE], int dice[NUM_DICE]);

// Ask user for category and score round for that category if available
void scoreRound(int dice[NUM_DICE], int categoryScores[NUM_FACES]);

// Prints the current dice rolls and re-rolls remaining
void printRoundState(int dice[NUM_DICE], int roll);

// Prints current total score of all saved categories
void printTotalScore(int categoryScores[NUM_FACES]);

// Flush stdin buffer
void flushStdin();

// Plays simple yahtzee
//
// Simple yahtzee consists of 6 rounds. In each round, 5 dice are rolled,
// and they may be re-rolled twice. The player saves dice they wish to keep
// which will not be re-rolled.
int main() {
  int dice[NUM_DICE], categoryScores[NUM_FACES];
  bool savedDice[NUM_DICE];
  initializeGame(categoryScores);
  // Play and score all rounds
  for (int gamesPlayed = 0; gamesPlayed < NUM_FACES; ++gamesPlayed) {
    playRound(savedDice, dice);
    scoreRound(dice, categoryScores);
  }
  printf("Game over.\n");
}

//////////////////////////////////
//// INITIALIZATION FUNCTIONS ////

// Sets up the game. Seed rand and mark every category as unscored
void initializeGame(int categoryScores[NUM_FACES]) {
  for (int i = 0; i < NUM_FACES; ++i) {
    categoryScores[i] = UNSCORED_CATEGORY;
  }
  int seed;
  printf("Enter seed: ");
  scanf("%d", &seed);
  // Flush the input buffer after every scanf call.
  flushStdin();
  srand(seed);
}

// Marks all die as unsaved. Used at the start of a round
void resetsavedDice(bool savedDice[NUM_DICE]) {
  for (int i = 0; i < NUM_DICE; i++) {
    savedDice[i] = false;
  }
}

//////////////////////////////////////
//// END INITIALIZATION FUNCTIONS ////

///////////////////////////////////
//// PLAYING A ROUND FUNCTIONS ////

// Play one round of simple yahtzee
void playRound(bool savedDice[NUM_DICE], int dice[NUM_DICE]) {
  resetsavedDice(savedDice);
  int roll = 0;
  // Initial roll before asking to save dice
  rollAllUnsavedDice(savedDice, dice);
  printRoundState(dice, 2);
  for (int roll = 0; roll < 2; ++roll) {
    getPlayerSaveDice(savedDice);
    rollAllUnsavedDice(savedDice, dice);
    printRoundState(dice, 1 - roll);
  }
}

// Obtains saved dice from player
void getPlayerSaveDice(bool savedDice[]) {
  char option;
  int die;
  bool reroll = false;
  while (!reroll) {
    printf("Enter dice to save or 'r' for reroll: ");
    // Read input and clear input buffer afterwards
    int scanfResult = scanf("%c", &option);
    flushStdin();
    // If some character successfully read
    if (scanfResult == 1) {
      // If user requests a reroll
      if (option == 'r') {
        reroll = true;
        continue;
      }
      // Else if user toggles saving of a die
      else if (isdigit(option) && 1 <= (die = atoi(&option)) && die <= NUM_DICE) {
        savedDice[die - 1] = !savedDice[die - 1];
        printf("Die %d is now %s\n", die, savedDice[die - 1] ? "saved" : "unsaved");
        continue;
      }
    }
    // Otherwise re-prompt for input
    printf("Error: invalid command. Enter 'r' for re-roll unsaved die or 1-5 to toggle saving die\n");
  }
}

// Re-roll all die that are not saved
void rollAllUnsavedDice(bool savedDice[NUM_DICE], int dice[NUM_DICE]) {
  for (int i = 0; i < NUM_DICE; i++) {
    if (!savedDice[i]) {
      dice[i] = 1 + rand() % NUM_FACES;
    }
  }
}

// Ask user for category and score round for that category if available
void scoreRound(int dice [NUM_DICE], int categoryScores[NUM_FACES]) {
  int categoryToSave = 0;
  char e;
   printf("Enter category to save score: ");
   scanf("%d", &categoryToSave);
   flushStdin();
   while (categoryToSave > NUM_FACES || categoryToSave <= 0 || categoryScores [categoryToSave - 1] != UNSCORED_CATEGORY){
	 printf("Error: invalid command. Enter 1-6 to save to an unused category\n");
	 printf("Enter category to save score: ");
	 scanf("%d", &categoryToSave); 
   	 flushStdin();
   }

   if (categoryScores[categoryToSave - 1] == UNSCORED_CATEGORY) {
	categoryScores[categoryToSave - 1] = 0;
	   int count = 0;
	   for (int i = 0; i < NUM_DICE;  ++i){
		   if (dice[i] == categoryToSave) {
			   categoryScores[categoryToSave - 1] += dice[i];
		   }
		   if (dice[i] != categoryToSave && categoryScores[categoryToSave-1] == UNSCORED_CATEGORY) {
			   categoryScores[categoryToSave - 1] = 0;
		   }
   	}	
   }
   //else {
//	 while (categoryScores[categoryToSave - 1] != UNSCORED_CATEGORY) {
//	   printf("Error: invalid command. Enter 1-6 to save to an unused category\n");
//	   printf("Enter category to save score: ");
//	   scanf("%d", &categoryToSave);
//	   flushStdin();
	   
  // }
  // }
   printTotalScore(categoryScores);
}	
  // 1) Ask the user for a category to save the round score to
  // 2) Check if the input category is scored or not using UNSCORED_CATEGORY
  // 3) Score the result for category i in categoryScores[i - 1]
  // 4) Print the current total score.

///////////////////////////////////////
//// END PLAYING A ROUND FUNCTIONS ////

////////////////////////////
//// PRINTING FUNCTIONS ////

// Prints the current dice rolls and re-rolls remaining
void printRoundState(int dice[NUM_DICE], int rerollsLeft) {
	int rolls = 2;
	
	printf("Dice: ");
	for (int i = 0; i < NUM_DICE ; i++) {
	 	printf("%d ", dice[i]);
	}
	printf("\n");
	if (rerollsLeft != 2){
		rolls = 1;
	}
	if (rolls == 2 ){
		printf("Rolls left: %d\n", rolls);
		rerollsLeft = rolls - 1;
		return;
	}
	else if(rerollsLeft == 1) {
		printf("Rolls left: %d\n", rerollsLeft);
		rerollsLeft = rolls -1;
		return;	
	}
	else if(rerollsLeft == 0) {
		printf("Rolls left: %d\n", rerollsLeft);
		return;
	}
}
  // Homework TODO: write code for this function.
  // Example output, if all dice are 1 and 2 rerolls are left:
  // Dice: 1 1 1 1 1
  // Rolls left: 2

// Prints current total score of all saved categories
void printTotalScore(int categoryScores[NUM_FACES]) {
	int total = 0;

	for (int i = 0; i < NUM_FACES; ++i) {
		printf("Category %d score: ", i+1 );
		if (categoryScores[i] == UNSCORED_CATEGORY) {
			printf("not scored\n");
	}
		else {
		printf("%d\n", categoryScores[i]);
		total += categoryScores[i];
		}
	}
	printf("Total Score: %d\n", total);
}
  // Homework TODO: write code for this function.
  // Example output, if the score for category i is 2i except
  // for category 2, which is unscored:
  // Category 1 score: 1
  // Category 2 score: not scored
  // Category 3 score: 6
  // Category 4 score: 8
  // Category 5 score: 10
  // Category 6 score: 12
  // Total Score: 27

////////////////////////////////
//// END PRINTING FUNCTIONS ////

// Flush stdin buffer
void flushStdin() {
  char c;
  // Skip all characters until end-of-file marker
  // or new line / carriage return
  while ( (c = getchar()) != EOF &&
          c != '\n' &&
          c != '\r' ) {};
}
