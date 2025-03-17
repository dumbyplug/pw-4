#include <stdio.h>

int alignment(char list[6][7]){
	int i, j, align, longest_alignment = 0;
	char symbol, longests_symbol;

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
	for(j = 0; j < 7; j++){
		align = 1;
		symbol = list[0][j];
		for(i = 1; i < 6; i++){
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

	printf("Longest For %c, %d consecutive alingment(s)\n", 
			longests_symbol, longest_alignment);
}

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
