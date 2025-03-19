int alignment(char list[6][7], char symbol){
	int i, j, align, longest_alignment = 0;

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
			if((align > longest_alignment) && (list[i][j] == symbol)){
				longest_alignment = align;
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
			if((align > longest_alignment) && (list[i][j] == symbol)){
				longest_alignment = align;
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
			if((align > longest_alignment) && (list[i][i - j] == symbol)){
				longest_alignment = align;
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
			if((align > longest_alignment) && (list[i][12 - i - j] == symbol)){
				longest_alignment = align;
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
			if((align > longest_alignment) && (list[j - i][j] == symbol)){
				longest_alignment = align;
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
			if((align > longest_alignment) && (list[6 - i - j][j] == symbol)){
				longest_alignment = align;
			}
		}
	}
	return longest_alignment;
} // done
