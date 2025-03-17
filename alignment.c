#include <stdio.h>

int alignment(char *list, int size){
	int align = 1;
	char symbol;
	symbol = list[0];
	for(int i = 1; i < size; i++){
		if(list[i] == symbol){
			align++;
		}
		else{
			printf("For %c, %d consecutive alingment(s)\n", symbol, align);
			symbol = list[i];
			align = 1;
		}
	}
}

int main(void){
	char list[] = "###@@****$$";
	int size = sizeof(list)/sizeof(list[0]);
	printf("%s\n\n", list);

	alignment(list, size);
	

	return 0;
}
