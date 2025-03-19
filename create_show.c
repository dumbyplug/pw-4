#include <stdio.h>

int x = 6, y = 7;

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
