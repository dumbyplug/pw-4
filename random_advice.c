#include <stdio.h>
#include <stdlib.h>
#include "move_possible.c"
#include "alignment.c"
#include "drop_disk.c"

int random_advice(char grid[6][7]){
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
	int longestForPlayer[7], longestForOpponent[7];
	char opponent;
	int row;
	if(player == '*')
		opponent = 'o';
	else 
		opponent = '*';

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

	int maxPlayer = 0, maxOpponent = 0;
	for(int i = 0; i < 7; i++){
		if(longestForPlayer[i] > maxPlayer){
			maxPlayer = longestForPlayer[i];
		}
		if(longestForOpponent[i] > maxOpponent){
			maxOpponent = longestForOpponent[i];
		}
	}

	int random_number = rand() % 7 + 1;
	int index = 0, reccomended;

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

	if(maxPlayer >= 4){
		return reccomended;
	}
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
