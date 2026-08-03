class Solution {
public:
    bool isRowValid(vector<vector<char>>& board, int r) {
        unordered_set<char> seen;
        for (int c = 0; c < 9; c++) {
            if (board[r][c] != '.') {
                if (seen.count(board[r][c])) return false;
                seen.insert(board[r][c]);
            }
        }
        return true;
    }

    bool isColValid(vector<vector<char>>& board, int c) {
        unordered_set<char> seen;
        for (int r = 0; r < 9; r++) {
            if (board[r][c] != '.') {
                if (seen.count(board[r][c])) return false;
                seen.insert(board[r][c]);
            }
        }
        return true;
    }

    bool isBoxValid(vector<vector<char>>& board, int srow, int scol) {
        unordered_set<char> seen;
        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] != '.') {
                    if (seen.count(board[i][j])) return false;
                    seen.insert(board[i][j]);
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // 1. Check all 9 rows and columns
        for (int i = 0; i < 9; i++) {
            if (!isRowValid(board, i) || !isColValid(board, i)) return false;
        }

        // 2. Check all 9 sub-boxes
        for (int r = 0; r < 9; r += 3) {
            for (int c = 0; c < 9; c += 3) {
                if (!isBoxValid(board, r, c)) return false;
            }
        }

        return true;
    }
};