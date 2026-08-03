class Solution {
public:
    // bool UL(vector<vector<int>>& grid, int& row, int& col, int n){
    //     //up-left
    //     if(row-2>=0 && col-1>=0){
    //         if(grid[row-2][col-1] == -1) return false;
    //         grid[row-2][col-1] = -1;
    //         row -=2; col-=1;
    //     }
    //     return true;
    // }

    // bool UR(vector<vector<int>>& grid, int& row, int& col, int n){
    //     //up-right
    //     if(row-2>=0 && col+1<n){
    //         if(grid[row-2][col+1] == -1) return false;
    //         grid[row-2][col+1] = -1;
    //         row-=2; col+=1;
    //     }
    //     return true;
    // }

    // bool LU(vector<vector<int>>& grid, int& row, int& col, int n){
    //     //left-up
    //     if(row-1>=0 && col-2>=0){
    //         if(grid[row-1][col-2] == -1) return false;
    //         grid[row-1][col-2] = -1;
    //         row-=1; col-=2;
    //     }
    //     return true;
    // }

    // bool LD(vector<vector<int>>& grid, int& row, int& col, int n){
    //     //left-down
    //     if(row+1<n && col-2>=0){
    //         if(grid[row+1][col-2] == -1) return false;
    //         grid[row+1][col-2] = -1;
    //         row+=1; col-=2;
    //     }
    //     return true;
    // }

    // bool DL(vector<vector<int>>& grid, int& row, int& col, int n){
    //     //down-left
    //     if(row+2<n && col-1>=0){
    //         if(grid[row+2][col-1] == -1) return false;
    //         grid[row+2][col-1] = -1;
    //         row+=2; col-=1;
    //     }
    //     return true;
    // }

    // bool DR(vector<vector<int>>& grid, int& row, int& col, int n){
    //     //down-right
    //     if(row+2<n && col+1<n){
    //         if(grid[row+2][col+1] == -1) return false;
    //         grid[row+2][col+1] = -1;
    //         row+=2; col+=1;
    //     }
    //     return true;
    // }

    // bool RD(vector<vector<int>>& grid, int& row, int& col, int n){
    //     //right-down
    //     if(row+1<n && col+2<n){
    //         if(grid[row+1][col+2] == -1) return false;
    //         grid[row+1][col+2] = -1;
    //         row+=1; col+=2;
    //     }
    //     return true;
    // }

    // bool RU(vector<vector<int>>& grid, int& row, int& col, int n){
    //     //right-up
    //     if(row-1>=0 && col+2<n){
    //         if(grid[row-1][col+2] == -1) return false;
    //         grid[row-1][col+2] = -1;
    //         row-=1; col+=2;
    //     }
    //     return true;
    // }

    bool isvalid(vector<vector<int>>& grid, int row, int col, int a, int n){
        if(row<0 || col<0 || row>=n || col>=n || grid[row][col]!=a){
            return false;
        }
        if(a == n*n-1) return true;
        int ans1 = isvalid(grid, row-2, col+1, a+1, n);
        int ans2 = isvalid(grid, row-2, col-1, a+1, n);
        int ans3 = isvalid(grid, row+2, col+1, a+1, n);
        int ans4 = isvalid(grid, row+2, col-1, a+1, n);
        int ans5 = isvalid(grid, row-1, col-2, a+1, n);
        int ans6 = isvalid(grid, row-1, col+2, a+1, n);
        int ans7 = isvalid(grid, row+1, col-2, a+1, n);
        int ans8 = isvalid(grid, row+1, col+2, a+1, n);
        return ans1||ans2||ans3||ans4||ans5|| ans6||ans7||ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isvalid(grid,0,0,0,grid.size());

    }
};