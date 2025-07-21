#include <stdio.h>
#include <stdbool.h>

bool isValidSudoku(char board[9][9]) {
    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1'; // convert char to 0-based index
                int boxIndex = (i / 3) * 3 + (j / 3);

                if (row[i][num] || col[j][num] || box[boxIndex][num]) {
                    return false;
                }

                row[i][num] = true;
                col[j][num] = true;
                box[boxIndex][num] = true;
            }
        }
    }
    return true;
}

int main() {
    char board[9][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (isValidSudoku(board)) {
        printf("The Sudoku board is valid.\n");
    } else {
        printf("The Sudoku board is NOT valid.\n");
    }

    return 0;
}
