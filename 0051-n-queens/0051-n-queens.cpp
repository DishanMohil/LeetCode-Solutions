class Solution {
public:

    bool istrue(int r, int c, int n, vector<string>& b){
        //for row
        for(int j = 0; j<n; j++){
            if(b[r][j]=='Q'){
                return false;
            }
        }
        //forcolumn
         for(int j = 0; j<n; j++){
            if(b[j][c]=='Q'){
                return false;
            }
        }
        //for diagonal
         for(int j = r,i = c; i>=0 && j>=0; i--,j--){
            if(b[j][i]=='Q'){
                return false;
            }
        }

        for(int j = r,i = c; i<n && j>=0; i++,j--){
            if(b[j][i]=='Q'){
                return false;
            }
        }

        for(int j = r,i = c; i>=0 && j<n; i--,j++){
            if(b[j][i]=='Q'){
                return false;
            }
        }

        for(int j = r,i = c; i<n && j<n; i++,j++){
            if(b[j][i]=='Q'){
                return false;
            }
        }

        return true;
    }


    void solve(vector<vector<string>>& ans, vector<string>& b, int n, int row){
        if(row == n){
            ans.push_back(b);
            return;
        }
        for(int j = 0; j < n; j++){
            if(istrue(row, j, n, b)){
                b[row][j] = 'Q';
                solve(ans, b, n, row+1);
                b[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n,string(n,'.'));

        solve(ans,b,n,0);
        return ans;

    }
};