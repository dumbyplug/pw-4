#include "alignment.c"
#include "drop_disk.c"
#include "move_possible.c"
#include "create_show.c"

void game(char player){
	char grid[6][7];
	createGrid(grid);


	char run = 1;
	int move;
	int *pmove = &move;
	while(run){
		showGrid(grid);

		printf("\nPlayer %c's move: ", player);
		scanf("%d", pmove);

		if(is_move_possible(grid, move)) 
			drop_disk(grid, move, player);


		if(player == '*')
			player = 'o';
		else
			player = '*';
	}
}

int main(void){
	game('*');
	return 0;
}
