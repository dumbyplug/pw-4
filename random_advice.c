#include <stdio.h>
#include <stdlib.h>
#include "alignment.c"
#include "drop_disk.c"
#include "create_show.c"
#include "move_possible.c"

int rnd_advice(char grid[6][7]){
	int min = 0,max = 0,index = 0;
	for (int i = 0; i < 7;i++) {
		if (is_move_possible(grid,i)){
			max +=1;
		}
	} 
	int arr[max];
	for (int move = 0; move < 7;move++) {
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

	printf("You can play at column %d",arr[rd_num-1]+1);
}

