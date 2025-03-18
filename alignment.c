#include <stdio.h>


int alignment(char list[6][7]){
	int i, j, align, longest_alignment = 0;
	char symbol, longests_symbol;

	// horizontal
	for(i = 0; i < 6; i++){
		align = 1;
		symbol = list[i][0];
		for(j = 1; j < 7; j++){
			if(list[i][j] == symbol){
				align += 1;
				if(j == 6){
					if((align > longest_alignment) && symbol){
						longest_alignment = align;
						longests_symbol = symbol;
					}
				}
			}
			else{
				if((align > longest_alignment) && symbol){
					longest_alignment = align;
					longests_symbol = symbol;
				}
				symbol = list[i][j];
				align = 1;
			}
		}
	}

	// vertical
	for(j = 0; j < 7; j++){
		align = 1;
		symbol = list[0][j];
		for(i = 1; i < 6; i++){
			if(list[i][j] == symbol){
				align += 1;
				if(i == 5){
					if((align > longest_alignment) && symbol){
						longest_alignment = align;
						longests_symbol = symbol;
					}
				}
			}
			else{
				if((align > longest_alignment) && symbol){
					longest_alignment = align;
					longests_symbol = symbol;
				}
				symbol = list[i][j];
				align = 1;
			}
		}
	}

	// diagonal left-to-right bottom 
	for(j = 0; j < 7; j++){
		align = 1;
		symbol = list[j % 6][0];
		for(i = j; i < 6; i++){
			if(list[i][i - j] == symbol){
				align++;
				if(i == 5){
					if((align > longest_alignment) && symbol){
						longest_alignment = align;
						longests_symbol = symbol;
					}
				}
			}
			else{
				if((align > longest_alignment) && symbol){
					longest_alignment = align;
					longests_symbol = symbol;
				}
				symbol = list[i][i - j];
				align = 1;
			}
		}
	}

	// diagonal right-to-left bottom 
	for(j = 6; j >= 0; j--){
		align = 1;
		symbol = list[6 - j][6];
		for(i = 6 - j; i < 6; i++){
			printf("%d %d\n", i, 12 - i - j);
			if(list[i][12 - i - j] == symbol){
				align++;
				if(i == 5){
					if((align > longest_alignment) && symbol){
						longest_alignment = align;
						longests_symbol = symbol;
					}
				}
			}
			else{
				if((align > longest_alignment) && symbol){
					longest_alignment = align;
					longests_symbol = symbol;
				}
				symbol = list[12 - i - j][j];
				align = 1;
			}
		}
	}

	printf("Longest For %c, %d consecutive alingment(s)\n", 
			longests_symbol, longest_alignment);
	return longest_alignment + longests_symbol * 10;
}

/*
 0 6
 1 5
 2 4
 3 3
 4 2
 5 1

 1 6
 2 5
 */

int main(void){
	char list[6][7] = {
		{0, 0 , 0 , 0 , 0 , 0 , 0 },
		{0, 0 , 0 , 0 ,'*', 0 ,'*'},
		{0, 0 , 0 , 0 ,'*','*', 0 },
		{0, 0 , 0 , 0 ,'*', 0 , 0 },
		{0, 0 , 0 ,'*','*', 0 , 0 },
		{0,'*','*','o','o','o','o'}
	};

	alignment(list);
	

	return 0;
}
