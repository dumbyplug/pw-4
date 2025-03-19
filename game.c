#include "create_show.c"
#include "random_advice.c"
#include <time.h>
#include <stdio.h>

// Function to check if it is draw
int is_grid_full(char grid[6][7]) {
    for (int col = 0; col < 7; col++) {
        if (is_move_possible(grid, col)) {
            return 0; // Grid is not full
        }
    }
    return 1; // Grid is full
}

char game_vs_ai(char player) {
    char ai;
    if (player == '*') {
        ai = 'o';
    } else {
        ai = '*';
    }

    char grid[6][7];
    createGrid(grid);

    int move;
    while (1) {
        printf("\x1b[H\x1b[2J");
        showGrid(grid);

        // Player Move
        do {
            printf("\nYour turn (%c): ", player);
            if (scanf("%d", &move) != 1 || move < 1 || move > 7 || !is_move_possible(grid, move - 1)) {
                printf("Invalid move. Try again.\n");
                while (getchar() != '\n');  // Clear input buffer
            } else {
                break;
            }
        } while (1);

        drop_disk(grid, move - 1, player);

        if (alignment(grid, player) >= 4) {
            printf("\x1b[H\x1b[2J");
            showGrid(grid);
            printf(" -- You won the game! --\n");
            return player;
        }

        if (is_grid_full(grid)) {
            printf("\x1b[H\x1b[2J");
            showGrid(grid);
            printf(" -- It's a draw! --\n");
            return 'D';
        }

        // AI Move
        int ai_move = advanced_advice(grid, ai);
        if (is_move_possible(grid, ai_move)) {
            drop_disk(grid, ai_move, ai);
        }

        if (alignment(grid, ai) >= 4) {
            printf("\x1b[H\x1b[2J");
            showGrid(grid);
            printf(" -- AI won the game! --\n");
            return ai;
        }

        if (is_grid_full(grid)) {
            printf("\x1b[H\x1b[2J");
            showGrid(grid);
            printf(" -- It's a draw! --\n");
            return 'D';
        }
    }
}
