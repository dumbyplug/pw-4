int horizontal(char list[6][7]){
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
	printf("Longest For %c, %d consecutive alingment(s)\n", 
			longest_alignment_symbol, longest_alignment);

} // done

int vertical(char list[6][7]){
	int i, j, align, longest_alignment = 0;
	char symbol, longest_alignment_symbol;
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
	printf("Longest For %c, %d consecutive alingment(s)\n", 
			longest_alignment_symbol, longest_alignment);

} // done

int diagonal_l_r_b(char list[6][7]){
	int i, j, align, longest_alignment = 0;
	char symbol, longest_alignment_symbol;
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
			printf("%d %d\n", i, i - j);
		}
		printf("\n");
	}
	printf("Longest For %c, %d consecutive alingment(s)\n", 
			longest_alignment_symbol, longest_alignment);
} // done

int diagonal_r_l_b(char list[6][7]){
	int i, j, align, longest_alignment = 0;
	char symbol, longest_alignment_symbol;
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
			printf("%d %d\n", i, 12 - i - j);
		}
		printf("\n");
	}
	printf("Longest For %c, %d consecutive alingment(s)\n", 
			longest_alignment_symbol, longest_alignment);
} // done

int diagonal_l_r_t(char list[6][7]){
	int i, j, align, longest_alignment = 0;
	char symbol, longest_alignment_symbol;
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
			printf("%d %d\n", j - i, j);
		}
		printf("\n");
	}

	printf("Longest For %c, %d consecutive alingment(s)\n", 
			longest_alignment_symbol, longest_alignment);
} // done

int diagonal_r_l_t(char list[6][7]){
	int i, j, align, longest_alignment = 0;
	char symbol, longest_alignment_symbol;
	// diagonal right-to-left bottom 

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
			printf("%d %d\n", 6 - i - j, j);
		}
		printf("\n");
	}

	printf("Longest For %c, %d consecutive alingment(s)\n", 
			longest_alignment_symbol, longest_alignment);
	return longest_alignment + longest_alignment_symbol * 10;
} // done

