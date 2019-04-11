#include "gameboard.h"

#include <stdlib.h>
#include <stdio.h>

// allocates space for the gameboard and its squares
gameboard* gameboard_create(int numRows, int numCols) {
    if (numRows < 3 || numCols < 3) {
        fprintf(stderr, "Error: board must be at least 4x4\n");
        exit(0);
    }

    gameboard* result = (gameboard*)malloc(sizeof(gameboard)); 
    result->numRows = numRows;
    result->numCols = numCols; 
    result->squares =(square**) malloc(numRows * sizeof(square*));
    for( int i = 0; i < numRows; i++){
	result->squares[i] = malloc(numCols * sizeof(square));	
    }
	   // Homework TODO: complete this function by adding code here
    gameboard_initialize(result);
    return result;
}

// deallocates space for the gameboard and its squares
void gameboard_destroy(gameboard* board) {
    for (int i = 0; i < board->numRows; i++) {
        free(board->squares[i]);
    }
    free(board->squares);
    free(board);
}

// sets coinsInBoard to 0, state to STILL_PLAYING, and all squares to EMPTY
void gameboard_initialize(gameboard* board) {
    board->coinsInBoard = 0;
    for (int i = 0; i < board->numRows; i++) {
	    for (int j = 0; j < board->numCols; j++){
	    board->squares[i][j] = EMPTY;
	    }
    }
    board->state = STILL_PLAYING;
    // Homework TODO: define this function
}

// returns RED_COIN, YELLOW_COIN, or EMPTY depending on square (row, col)
square gameboard_square(const gameboard board, int row, int col) {
    if (0 <= row && row < board.numRows && 0 <= col && col < board.numCols) {
        return board.squares[row][col];
    } else {
        fprintf(stderr, "Error: board index %d %d out of bounds\n", row, col);
        exit(0);
    }
}

// attempts to insert coin into column col for player p
bool gameboard_insert_coin(gameboard* board, int col, player p) {
	int i = board->numRows - 1;
	if (board->squares[0][col] != EMPTY){
		return false;
	}
	while (gameboard_square(*board, i, col) != EMPTY && i > 0) {
		i -= 1;
	}
	if (gameboard_square(*board, i , col) == EMPTY) {
		board->squares[i][col] = (p == RED_PLAYER?RED_COIN:YELLOW_COIN);
		board->coinsInBoard += 1;
		return true;
	}
	else {
		return false;
	}
    // Homework TODO: define this function
}
// prints the coins currently in the board
void gameboard_print(const gameboard board) {
    for (int i = 0; i < board.numRows; i++) {
        for (int j = 0; j < board.numCols; j++) {
            switch (gameboard_square(board, i, j)) {
                case EMPTY:
                    printf("  ");
                    break;
                case RED_COIN:
                    printf("R ");
                    break;
                case YELLOW_COIN:
                    printf("Y ");
                    break;
            }
        }
        printf("\n");
    }
    for (int j = 0; j < board.numCols - 1; j++) {
        printf("==");
    }
    printf("=\n");
}

// returns true if STILL_PLAYING, false otherwise
bool gameboard_still_playing(const gameboard board) {
    return board.state == STILL_PLAYING;
}

// returns state field
gamestate gameboard_state(const gameboard board) {
    return board.state;
}

// check if game is over due to square (row, col) modification
void gameboard_check_square(gameboard* board, int row, int col) { 
	
	gameboard_check_square_horizontal(board, row, col);
	gameboard_check_square_vertical(board, row, col);
	gameboard_check_square_diagonal(board,row,col);

	// Homework TODO: define this function
}

// check horizontal strips containing square (row, col)
void gameboard_check_square_horizontal(gameboard* board, int row, int col) {
   //square color_coin = gameboard_square(board, row, col);
    int adx = 0;
    int n = 0;
    int i;

    while (gameboard_square(*board,adx,col) == EMPTY && adx < board->numRows){ 
	    adx+=1;
    }
    if (board->squares[adx][col] == EMPTY) {
	    return;
    }
    for(i = 1; i < board->numCols; ++i){
		if ((col-i >= 0)&&(board->squares[adx][col] == board->squares[adx][col-i])){
			n += 1;
		}
		else {
			break;
		}
	}
	for(i = 1; i < board->numCols; ++i){
		if ((col+i < board->numCols)&&(board->squares[adx][col] == board->squares[adx][col+i])){
			n += 1;
		}
		else {
			break;
		}
	}
	n += 1;
    if(n>=4){
        board->state = (board->squares[adx][col]==RED_COIN?RED_WINS:YELLOW_WINS);
    }
}

	// Homework TODO: define this function

// check vertical strips containing square (row, col)
void gameboard_check_square_vertical(gameboard* board, int row, int col) {
    int adx = 0;
    int n = 0;
    int i;
    while (gameboard_square(*board, adx ,col) == EMPTY && adx < board->numRows){
        adx+=1;
    }
    if(board->squares[adx][col] == EMPTY){
        return;
    }
    for (i = 1; i < board->numCols;++i){
        if((adx-i>=0)&&(board->squares[adx][col] == board->squares[adx - i][col])){
            n+=1;
        }
        else{
            break;
        }
    }
    for (i = 1; i < board->numCols;++i){
        if((adx + i<board->numRows)&&(board->squares[adx][col]==board->squares[adx + i][col])){
            n+=1;
        }
        else{
            break;
        }
    }
    n+=1;
    if(n>=4){
        board->state = (board->squares[adx][col] == RED_COIN?RED_WINS:YELLOW_WINS);
    }
}	

	// Homework TODO: define this function
// check diagonal strips containing square (row, col)
void gameboard_check_square_diagonal(gameboard* board, int row, int col) {
    int usrrow = 0;
    int n=0;
    int i;
    while (gameboard_square(*board,usrrow,col) == EMPTY&&usrrow<board->numRows){
        usrrow+=1;
    }
    if(board->squares[usrrow][col] == EMPTY){
        return;
    }
    for(i = 1; i < board->numCols; ++i){
		if ((usrrow-i >= 0)&&(col-i >= 0)&&(board->squares[usrrow][col] == board->squares[usrrow-i][col-i])){
			n += 1;
		}
		else {
			break;
		}
	}

	for(i = 1; i < board->numCols; ++i){
		if ((usrrow+i < board->numRows)&&(col+i < board->numCols)&&(board->squares[usrrow][col] == board->squares[usrrow+i][col+i])){
            n += 1;
		}
		else {
			break;
		}
	}
	n += 1;
    if(n>=4){
        board->state = (board->squares[usrrow][col]==RED_COIN?RED_WINS:YELLOW_WINS);
    }
    n = 0;
    for(i = 1; i < board->numCols; ++i){
		if ((usrrow-i >= 0)&&(col+i < board->numCols)&&(board->squares[usrrow][col] == board->squares[usrrow-i][col+i])){
			n += 1;
		}
		else {
			break;
		}
	}
	for(i = 1; i < board->numRows; ++i){
		if ((usrrow+i < board->numRows)&&(col-i >= 0)&&(board->squares[usrrow][col] == board->squares[usrrow+i][col-i])){
			n += 1;
		}
		else {
			break;
		}
	}
    n += 1;
    if(n>=4){
        board->state = (board->squares[usrrow][col]==RED_COIN?RED_WINS:YELLOW_WINS);
    }
}



	// Homework TODO: define this function


// changes state to RED_WINS or YELLOW_WINS
void gameboard_declare_winner(gameboard* board, square color) {
	
	if (board->state == RED_WINS){
		printf("Game over: red wins.\n");
	}
	else if (board->state == YELLOW_WINS) {
		printf("Game over: yellow wins.\n");
	}
	else{
		printf("Game over: tie.\n");
	}
	// Homework TODO: define this function
}
