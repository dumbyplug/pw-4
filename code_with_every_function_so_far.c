#include <stdio.h>
#include <stdlib.h>

int x = 6, y = 7, row = 0;

int is_move_possible(char grid[6][7], int move){
    /*
    This function checks if the move is possible through that column
    Input:
        grid[6][7]: a matrix consisting of characters '*' or 'o'
        move: integer, a number between 1 and 7
    Output:
        either 0 - move is not possible or 1 -move is possible
    */

    //invalid move that exceeds the row count
    if ((move < 0) || (move > 6)){
        return 0;
    }

    //if 6th row of the grid is empty
    if (grid[0][move] != ' '){
        return 0;
    }

    return 1;
}

void drop_disk(char grid[6][7], int move, char character){
    /*
    This function drops a disk into the aviable place in the grid if possible, if it's not possible it does nothing
    Input:
        grid: matrix consiting of characters
        move: integer, the column it will fall
        character: character, that basically shows whose turn it is
    Output:
        void: it drops a disk into the empty place
    */
    for(int i = 5; i >= 0; i--){
        if(grid[i][move] == ' '){
            grid[i][move] = character;
            row = i;
            break;
        }
    }
}

void createGrid(char grid[6][7]) {
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			grid[i][j] = ' ';
		}
	}
}

void showGrid(char grid[6][7]) {
	for (int i = -1; i < x + 1; i++)
	{
		for (int j = -1; j < y + 1; j++)
		{
			if (j == -1 || j == y) {
				if (i > -1 && i < x)
					printf("%d ", x - i);
				else
					printf("  ");
			}
			else if (i == -1 || i == x) {
				if (j > -1 && j < y)
					printf("%d ", j + 1);
				else
					printf("  ");
			}
			else if (i >= 0 && i < x && j >= 0 && j < y) {
				printf("%c ", grid[i][j]);
			}
		}
		printf("\n");
	}
}

int rnd_advice(char grid[6][7]){
	int min = 0,max = 0,index = 0;
	for (int i = 0; i < 7; i++) {
		if (is_move_possible(grid,i)){
			max +=1;
		}
	} 
	int arr[max];
	for (int move = 0; move < 7; move++) {
		if (is_move_possible(grid,move)){
			arr[index] = move;
			printf("array: %d\n",arr[index]);
			index += 1;
		}
	}
        // Find the random number in the range [min, max]
    int rd_num = rand() % (max - min + 1) + min;
	printf("%d\n",rd_num);
	printf("%d\n",max);

	printf("You can play at column %d",arr[rd_num - 1] + 1);
} 

int alignment(char list[6][7]){
	int i, j, align, longest_alignment = 0;
	char symbol, longest_alignment_symbol;

	// horizontal
	for(i = 0; i < 6; i++){
		align = 1;
		for(j = 0; j < 7 - 1; j++){
			if(list[i][j] == list[i][j + 1]){
				align++;
			}
			else {
				align = 1;
			}
			if((align > longest_alignment) && (list[i][j] != ' ')){
				longest_alignment = align;
				longest_alignment_symbol = list[i][j];
			}
		}
	}
	// vertical
	for(j = 0; j < 7; j++){
		align = 1;
		for(i = 1; i < 6 - 1; i++){
			if(list[i][j] == list[i + 1][j]){
				align++;
			}
			else {
				align = 1;
			}
			if((align > longest_alignment) && (list[i][j] != ' ')){
				longest_alignment = align;
				longest_alignment_symbol = list[i][j];
			}
		}
	}
	// diagonal left-to-right bottom 
	for(j = 0; j < 7 - 1; j++){
		align = 1;
		for(i = j; i < 6 - 1; i++){
			if(list[i][i - j] == list[i + 1][i - j + 1]){
				align++;
			}
			else {
				align = 1;
			}
			if((align > longest_alignment) && (list[i][i - j] != ' ')){
				longest_alignment = align;
				longest_alignment_symbol = list[i][i - j];
			}
		}
	}

	// diagonal left-to-right top
	for(j = 6; j > 0; j--){
		align = 1;
		for(i = 6 - j; i < 6 - 1; i++){
			if(list[i][12 - i - j] == list[i + 1][12 - i - j - 1]){
				align++;
			}
			else {
				align = 1;
			}
			if((align > longest_alignment) && (list[i][12 - i - j] != ' ')){
				longest_alignment = align;
				longest_alignment_symbol = list[i][12 - i - j];
			}
		}
	}
	// diagonal right-to-left bottom 
	for(i = 1; i < 6; i++){
		align = 1;
		for(j = i; j < 7 - 1; j++){
			if((j - i) > 4) continue;
			if(list[j - i][j] == list[j - i + 1][j + 1]){
				align++;
			}
			else {
				align = 1;
			}
			if((align > longest_alignment) && (list[j - i][j] != ' ')){
				longest_alignment = align;
				longest_alignment_symbol = list[j - i][j];
			}
		}
	}
	// diagonal right-to-left top
	for(i = 1; i < 6; i++){
		align = 1;
		for(j = 6 - i; j > 0; j--){
			if((6 - i - j) > 4) continue;
			if(list[6 - i - j][j] == list[6 - i - j + 1][j - 1]){
				align++;
			}
			else {
				align = 1;
			}
			if((align > longest_alignment) && (list[6 - i - j][j] != ' ')){
				longest_alignment = align;
				longest_alignment_symbol = list[6 - i - j][j];
			}
		}
	}
	return longest_alignment + longest_alignment_symbol * 10;
} // done

void advance_recommend(char grid[6][7], char character){
    int length = alignment(grid), recommend = 0;
    for(int i = 0; i < 7; i++){
        drop_disk(grid, i, character);
        int holdthis = alignment(grid);
        if(length <= holdthis){
            recommend = i;
        }
        grid[row][i] = ' ';
    }return recommend;
}

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
