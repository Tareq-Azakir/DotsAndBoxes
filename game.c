
#include <stdio.h>
#include "board.h"
#include "game.h"

static char boxes[ROWS][COLS] = {{0}};

static int claimBoxes(int player) {
    int claimed = 0;

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (boxes[row][col] != 0) {
                continue;
            }

            if (horizontal[row][col] &&
                horizontal[row + 1][col] &&
                vertical[row][col] &&
                vertical[row][col + 1]) {

                boxes[row][col] = (char)player;
                setBoxOwner(row, col, (char)player);
                claimed++;
            }
        }
    }

    return claimed;
}

void playGame(void) {
    int scoreA = 0, scoreB = 0;
    int player = 'A';
    int r1, c1, r2, c2;

    while (scoreA + scoreB < ROWS * COLS) {
        displayBoard();

        printf("\nPlayer %c's turn\n", player);
        printf("Enter row1 col1 row2 col2: ");

        if (scanf("%d %d %d %d", &r1, &c1, &r2, &c2) != 4) {
            printf("Invalid input. Game ended.\n");
            return;
        }

        if (!drawLine(r1, c1, r2, c2)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        int claimed = claimBoxes(player);

        if (player == 'A') {
            scoreA += claimed;
        } else {
            scoreB += claimed;
        }

        printf("\nPlayer A: %d | Player B: %d\n",
               scoreA, scoreB);

        if (claimed > 0) {
            printf("Player %c completed %d box(es)!\n",
                   player, claimed);
        } else {
            player = (player == 'A') ? 'B' : 'A';
        }
    }

    displayBoard();

    printf("\nFINAL SCORE\n");
    printf("Player A: %d\n", scoreA);
    printf("Player B: %d\n", scoreB);

    if (scoreA > scoreB) {
        printf("Player A wins!\n");
    } else if (scoreB > scoreA) {
        printf("Player B wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}
