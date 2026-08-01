class Solution {
public:
    
    void sumC(int start, vector<int>& c,vector<int> a,vector<vector<int>>& ans, int t){

        if(t == 0){
            ans.push_back(a);
            return;
        }
        if(t<0) return;

        for(int i = start; i<c.size(); i++){
            a.push_back(c[i]);
            sumC(i,c,a,ans,t-c[i]);
            a.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        sumC(0,candidates,a,ans,target);
        return ans;
    }
};