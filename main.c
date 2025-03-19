#include "create_show.c"
#include "random_advice.c"

char game(char player){
	char initialSymbol = player;
	char grid[6][7];
	createGrid(grid);

	char run = 1;
	int move;
	while(run){
		//printf("\x1b[H\x1b[2J");
		showGrid(grid);

		printf("You can play on %d\n", advanced_advice(grid, player) + 1);
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
	if(initialSymbol == '*')
		return 'o';
	return '*';
}

int main(void){
	game('*');
	return 0;
}
