#include "create_show.c"
#include "random_advice.c"
#include <time.h>

char game(char player){
	srand(time(NULL));
	char initialSymbol = player;
	char grid[6][7];
	createGrid(grid);

	char run = 1;
	int move;
	while(run){
		printf("\x1b[H\x1b[2J");
		showGrid(grid);

		printf("You can play on %d\n", advanced_advice(grid, player) + 1);
		printf("\nPlayer %c's move: ", player);
		scanf("%d", &move);

		if(is_move_possible(grid, move - 1)){
			drop_disk(grid, move - 1, player);

			if(alignment(grid, player) >= 4){
				printf("\x1b[H\x1b[2J");
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
	if(initialSymbol == '*')
		return 'o';
	return '*';
}

char game_vs_ai(char player){
	srand(time(NULL));
	char ai;
	char grid[6][7];
	createGrid(grid);
	if(player == '*')
		ai = 'o';
	else
		ai = '*';

	char run = 1;
	int move;
	while(run){
		printf("\x1b[H\x1b[2J");
		showGrid(grid);

		printf("\nYour turn: ", player);
		scanf("%d", &move);

		if(is_move_possible(grid, move - 1)){
			drop_disk(grid, move - 1, player);

			if(alignment(grid, player) >= 4){
				printf("\x1b[H\x1b[2J");
				showGrid(grid);
				printf(" -- You won the game --\n");
				run = 0;
			}
		}

		drop_disk(grid, advanced_advice(grid, ai), ai);
		if(alignment(grid, ai) >= 4){
			printf("\x1b[H\x1b[2J");
			showGrid(grid);
			printf(" -- Ai won the game --\n");
			run = 0;
		}
	}
}

int main(void){
	game_vs_ai('*');
	return 0;
}
