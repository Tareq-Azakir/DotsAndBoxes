# Dots and Boxes — Sprint 1

## Description
A two-player console-based Dots and Boxes game implemented in C using a 4 × 5 grid of boxes.

## Project Structure
- `main.c` — Program entry point.
- `board.c` and `board.h` — Board management.
- `game.c` and `game.h` — Game logic and player turns.
- `Makefile` — Compilation and linking.

## Compilation
Run `make` to compile the program.

Run `./dotsandboxes.exe` to start the game.

## Gameplay
Players A and B take turns connecting adjacent dots by entering four coordinates: row1, col1, row2, col2. Completing a box awards a point to the player.

## Environment
The game was compiled and tested on Alpine Linux using Oracle VirtualBox.

## Debugging
GDB was used to set breakpoints, step through functions, and inspect local variables.

Valgrind reported zero memory errors and no memory leaks during the tested gameplay sequence.