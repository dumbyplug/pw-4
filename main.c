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
		printf("\x1b[H\x1b[2J");
		showGrid(grid);

		printf("\nPlayer %c's move: ", player);
		scanf("%d", &move);

		if(is_move_possible(grid, move - 1)){
			drop_disk(grid, move - 1, player);

			if(alignment(grid) % 10 == 4){
				printf("\n==============\n"
						"The player %c won\n", (char)(alignment(grid) / 10));
				run = 0;
				showGrid(grid);
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
