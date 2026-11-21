
#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int horizontal[ROWS + 1][COLS] = {0};
int vertical[ROWS][COLS + 1] = {0};
static char boxOwners[ROWS][COLS] = {{0}};


void displayBoard(void) {
    printf("\n    ");

    for (int col = 0; col <= COLS; col++) {
        printf("%4d", col);
    }
    printf("\n");

    for (int row = 0; row <= ROWS; row++) {
        printf("%d   ", row);

        for (int col = 0; col <= COLS; col++) {
            printf(".");

            if (col < COLS) {
                printf(horizontal[row][col] ? "--- " : "    ");
            }
        }
        printf("\n");

        if (row < ROWS) {
            printf("    ");

            for (int col = 0; col <= COLS; col++) {
                printf(vertical[row][col] ? "|" : " ");

                if (col < COLS) {
                    printf(" %c  ",
                        boxOwners[row][col] ?
                        boxOwners[row][col] : ' ');
                }
            }
            printf("\n");
        }
    }
}



int drawLine(int r1, int c1, int r2, int c2) {
    if (r1 < 0 || r1 > ROWS || r2 < 0 || r2 > ROWS ||
        c1 < 0 || c1 > COLS || c2 < 0 || c2 > COLS) {
        return 0;
    }

    if (r1 == r2 && abs(c1 - c2) == 1) {
        int col = c1 < c2 ? c1 : c2;

        if (horizontal[r1][col]) {
            return 0;
        }

        horizontal[r1][col] = 1;
        return 1;
    }

    if (c1 == c2 && abs(r1 - r2) == 1) {
        int row = r1 < r2 ? r1 : r2;

        if (vertical[row][c1]) {
            return 0;
        }

        vertical[row][c1] = 1;
        return 1;
    }

    return 0;
}

void setBoxOwner(int row, int col, char player) {
    if (row >= 0 && row < ROWS &&
        col >= 0 && col < COLS) {
        boxOwners[row][col] = player;
    }
}

