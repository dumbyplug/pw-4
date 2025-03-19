#include <stdio.h>
#include <stdlib.h>
#include "move_possible.c"
#include "alignment.c"
#include "drop_disk.c"

int random_advice(char grid[6][7]){
	/*
	This function gives user a random advice based on the move_possible functin, if the move is possible on that random given place it returns that column, if it's not it gives another random advice
	Input:
		grid[6][7]: a 6x7 matrix with characters
	Output:
		integer: randomly assigned advice
	*/
	int random_number = rand() % 7 + 1;
	int index = 0;
	while(1){
		if(is_move_possible(grid, index % 7)){
			random_number--;
			if(random_number <= 0){
				return index % 7;
			}
		}
		index++;
	}
}

int advanced_advice(char grid[6][7], char player){
	/*
	This function gives advice to the users or to the bot, based on alignment function. We check each possible column and using alignment function we assign the column with longest possible alignment to a variable and return that column
	Input:
		grid[6][7]: a 6x7 matrix
		player: character
	Output:
		advancely recommended column returns best place to drop the disk
	*/
	int longestForPlayer[7], longestForOpponent[7];
	char opponent;
	int row;

	//we make sure of player an opponent's disk color
	if(player == '*')
		opponent = 'o';
	else 
		opponent = '*';

	//this loop determines move possibilities
	for(int i = 0; i < 7; i++){
		if(is_move_possible(grid, i)){
			row = drop_disk(grid, i, player);
			longestForPlayer[i] = alignment(grid, player);
			grid[row][i] = opponent;
			longestForOpponent[i] = alignment(grid, opponent);
			grid[row][i] = ' ';
		}
		else {
			longestForPlayer[i] = 0;
			longestForOpponent[i] = 0;
		}
	}

	//this loop determines max alignment for both players
	int maxPlayer = 0, maxOpponent = 0;
	for(int i = 0; i < 7; i++){
		if(longestForPlayer[i] > maxPlayer){
			maxPlayer = longestForPlayer[i];
		}
		if(longestForOpponent[i] > maxOpponent){
			maxOpponent = longestForOpponent[i];
		}
	}

	//we generate a random number to make different move choices
	int random_number = rand() % 7 + 1;
	int index = 0, reccomended;

	//finding best aligned column
	while(1){
		if(longestForPlayer[index % 7] == maxPlayer){
			random_number--;
			if(random_number <= 0){
				reccomended = index % 7;
				break;
			}
		}
		index++;
	}

	//if there's winning move we recommend that one
	if(maxPlayer >= 4){
		return reccomended;
	}
	//if player can't win they either block opponent's winning move or they play best choice 
	else if(maxOpponent >= 4){
		for(int i = 0; i < 7; i++){
			if(longestForOpponent[i] == maxOpponent){
				return i;
			}
		}
	}
	else
		return reccomended;
}
