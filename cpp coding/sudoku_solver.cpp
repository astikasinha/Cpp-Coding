#include <bits/stdc++.h>
using namespace std;

bool issafe(int row, int col, vector<vector<int>>& board, int val) {
    for (int i = 0; i < 9; i++) {
        // Row check
        if (board[row][i] == val) {
            return false;
        }
        // Column check
        if (board[i][col] == val) {
            return false;
        }
        // 3x3 subgrid check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board) {
    int n = board.size();
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Cell is empty
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (issafe(row, col, board, val)) {
                        board[row][col] = val;
                        // Recursive call to solve for the next cell
                        if (solve(board)) {
                            return true;
                        } else {
                            // Backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                // No valid number can be placed in this cell, so backtrack
                return false;
            }
        }
    }
    // All cells are filled
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku) {
    solve(sudoku);
    // No need to print the final sudoku here as per the problem statement
    // Just fill the values in the given matrix
}

int main() {
    // Example to test the solveSudoku function
    vector<vector<int>> sudoku = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    solveSudoku(sudoku);

    // Printing the solved Sudoku
    for (const auto &row : sudoku) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}

