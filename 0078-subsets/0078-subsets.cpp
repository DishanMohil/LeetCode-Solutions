class Solution {
public:

    void all(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>>& a){
        if(i == arr.size()){
            a.push_back({ans});
            return;
        }

        ans.push_back(arr[i]);
        all(arr,ans,i+1,a);

        ans.pop_back();
        all(arr,ans,i+1,a);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> a;
        vector<int> ans;
        all(arr,ans,0,a);
        return a;
    }
};