#include <stdio.h>

char board[3][3]; // Game board

void resetBoard() {
    for (int i = 0, count = '1'; i < 3; i++) {
        for (int j = 0; j < 3; j++, count++)
            board[i][j] = count;
    }
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}

int makeMove(char mark) {
    int pos;
    printf("Player %c, enter position (1-9): ", mark);
    scanf("%d", &pos);

    if (pos < 1 || pos > 9) return 0;

    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = mark;
        return 1;
    }
    return 0;
}

char checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return board[i][i];
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return board[1][1];

    return ' ';
}

int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

int main() {
    char winner = ' ';
    char player = 'X';
    resetBoard();

    printf("=== TIC TAC TOE ===\n");
    displayBoard();

    while (winner == ' ' && !isDraw()) {
        if (!makeMove(player)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        displayBoard();
        winner = checkWin();

        if (winner == ' ')
            player = (player == 'X') ? 'O' : 'X';
    }

    if (winner != ' ')
        printf("🎉 Player %c wins!\n", winner);
    else
        printf("😮 It's a draw!\n");

    return 0;
}
