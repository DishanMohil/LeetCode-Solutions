class Solution {
public:

    bool istrue(vector<vector<char>>& b, int r, int c, char dig){
        for(int j = 0; j<9; j++){
            if(b[r][j]==dig){
                return false;
            }
        }
        for(int j = 0; j<9; j++){
            if(b[j][c]==dig){
                return false;
            }
        }
        int srow = (r/3)*3;
        int scol = (c/3)*3;
        for(int i = srow; i<=srow+2; i++){
            for(int j = scol; j<=scol+2; j++){
                if(b[i][j]==dig){
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& b, int row, int col){
        if(row == 9){
            return true;
        }
        int nrow = row;
        int ncol = col+1;
        if(ncol == 9){
            nrow = row+1;
            ncol = 0;
        }
        if(b[row][col]!='.'){
            return solve(b,nrow,ncol);
        }
        for(char i = '1'; i<='9'; i++){
            if(istrue(b, row, col, i)){
                b[row][col]=i;
                if(solve(b,nrow,ncol)){
                    return true;
                }
                b[row][col]='.';
            } 
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& b) {
        solve(b,0,0);
        // return;
    }
};