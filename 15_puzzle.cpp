#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4 // Size of the puzzle (N x N)

// Structure to represent a puzzle state
typedef struct {
    int puzzle[N][N];
    int x, y; // Position of empty tile
} PuzzleState;

// Function to initialize the puzzle state
PuzzleState* initializePuzzle() {
    PuzzleState* state = (PuzzleState*)malloc(sizeof(PuzzleState));
    int count = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            state->puzzle[i][j] = count++;
        }
    }
    state->puzzle[N-1][N-1] = 0; // Empty tile represented by 0
    state->x = N-1;
    state->y = N-1;
    return state;
}

// Function to print the puzzle state
void printPuzzle(PuzzleState* state) {
    printf("-------------\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("| %2d ", state->puzzle[i][j]);
        }
        printf("|\n");
        printf("-------------\n");
    }
    printf("\n");
}

// Function to check if a move is valid
bool isValidMove(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Function to swap two tiles
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform a move in the puzzle
void move(PuzzleState* state, int newX, int newY) {
    if (!isValidMove(newX, newY)) {
        printf("Invalid move!\n");
        return;
    }
    swap(&state->puzzle[state->x][state->y], &state->puzzle[newX][newY]);
    state->x = newX;
    state->y = newY;
}

int main() {
    PuzzleState* puzzle = initializePuzzle();
    printf("Initial puzzle state:\n");
    printPuzzle(puzzle);

    // Example move: Move empty tile up
    printf("Move empty tile up:\n");
    move(puzzle, puzzle->x - 1, puzzle->y);
    printPuzzle(puzzle);

    // Example move: Move empty tile left
    printf("Move empty tile left:\n");
    move(puzzle, puzzle->x, puzzle->y - 1);
    printPuzzle(puzzle);

    free(puzzle);
    return 0;
}

