
#ifndef BOARD_H
#define BOARD_H

#define ROWS 4
#define COLS 5

extern int horizontal[ROWS + 1][COLS];
extern int vertical[ROWS][COLS + 1];

void displayBoard(void);
int drawLine(int r1, int c1, int r2, int c2);
void setBoxOwner(int row, int col, char player);

#endif
