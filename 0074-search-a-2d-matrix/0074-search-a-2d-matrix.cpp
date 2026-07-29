class Solution {
public:
    bool search(vector<vector<int>>& m, int tar, int row){
        int st = 0, end = m[row].size()-1;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(tar == m[row][mid]){
                return true;
            }else if(tar<m[row][mid]){
                end = mid-1;
            }else if(tar>m[row][mid]){
                st = mid+1;
            }
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& mt, int t) {
        int n = mt.size(), m = mt[0].size();
        int st = 0, end = n-1;
        while(st<=end){
            int mid = st + (end-st)/2;
            if(t<=mt[mid][m-1] && t>=mt[mid][0]){
                return search(mt,t,mid);
            }else if(t<mt[mid][0]){
                end = mid-1;
            }else if(t>mt[mid][m-1]){
                st = mid+1;
            }
        }
        return false;
    }
};