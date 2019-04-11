#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "gameboard.h"

void gameboard_play(gameboard* board, int rows, int cols, square color);

int main() {
    printf("Enter the number of rows and columns of your gameboard: ");
    int rows, cols, userCol;
    bool txt;
    square color;
    player p;
    scanf("%d %d", &rows, &cols);
    gameboard* board = gameboard_create(rows, cols);
    gameboard_print(*board);
        
    while (gameboard_still_playing(*board)) {
	do {
	    txt = true;
	    if (gameboard_still_playing(*board)){
		    p = RED_PLAYER;
		    color = RED_COIN;
		    printf("Enter column for red coin: ");
		    scanf(" %d", &userCol);
		    txt = gameboard_insert_coin(board, userCol, p);
	    if (txt == false){
		    printf("Column %d is full\n", userCol);
	    }
	    gameboard_print(*board);
	    if (board->coinsInBoard == rows*cols){
		    board->state = TIE;
	    }
	    gameboard_check_square(board, board->numRows, userCol);
	}
    }
       	while( txt == false);
    do {
	    txt = true;
	    if (gameboard_still_playing(*board)){
		    p = YELLOW_PLAYER;
		    color = YELLOW_COIN;
		    printf("Enter column for yellow coin: ");
		    scanf(" %d", &userCol);
		    txt = gameboard_insert_coin(board, userCol, p);
		    if (txt == false){
			    printf("Column %d is full\n", userCol);
		    }
		    gameboard_print(*board);
		    if (board->coinsInBoard == rows*cols){
			    board->state = TIE;
		    }
		    gameboard_check_square(board, board->numRows, userCol);
	    }
    }
    while (txt == false);
}
    gameboard_declare_winner(board,color);
    // Homework TODO: complete this function
    gameboard_destroy(board);
}
