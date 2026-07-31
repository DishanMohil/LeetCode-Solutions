class Solution {
public:
    
    void all(vector<int>& arr, int i, vector<vector<int>>& per){
        if(i == arr.size()){
            per.push_back({arr});
            return;
        }
        for(int j = i; j < arr.size();j++){
            swap(arr[i],arr[j]);
            all(arr, i+1, per);
            swap(arr[i],arr[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> per;
        all(nums, 0, per);
        return per;
    }
};