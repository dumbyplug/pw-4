#include "alignment.c"
#include "drop_disk.c"
#include "move_possible.c"
#include "create_show.c"

#include <stdlib.h>

void game(char player){
	char grid[6][7];
	createGrid(grid);

	char run = 1;
	int move;
	while(run){
		//printf("\x1b[H\x1b[2J");
		showGrid(grid);

		printf("\nPlayer %c's move: ", player);
		scanf("%d", &move);

		if(is_move_possible(grid, move - 1)){
			drop_disk(grid, move - 1, player);

			if(alignment(grid, player) >= 4){
				showGrid(grid);
				printf(" -- Player %c won the game --\n", player);
				run = 0;
			}
			if(player == '*')
				player = 'o';
			else
				player = '*';
		}

	}
}

int main(void){
	game('*');
	return 0;
}
