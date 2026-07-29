class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        int r = 0, c = 0; vector<int> ans;
        while(n>0 && m>0){
            for(int i = 0; i < n; i++){
                ans.push_back(matrix[r][c++]);
            }
            m--; c--;
            if(m == 0) break;
            for(int i = 0; i < m; i++){
                ans.push_back(matrix[++r][c]);
            }
            n--;
            if(n == 0) break;
            for(int i = 0; i < n; i++){
                ans.push_back(matrix[r][--c]);
            }
            m--;
            if(m == 0) break;
            for(int i = 0; i < m; i++){
                ans.push_back(matrix[--r][c]);
            }
            c++; n--;
        }
        return ans;
    }
};