class Solution {
public:

    void all(vector<int>& arr, int i, vector<vector<int>>& per){
        if(i == arr.size()){
            per.push_back(arr);
            return;
        }
        unordered_set<int> used;
        for(int j = i; j < arr.size();j++){

            if(used.count(arr[j])) continue;

            used.insert(arr[j]);
            
            swap(arr[i],arr[j]);

            all(arr, i+1, per);

            swap(arr[j],arr[i]);

            // used.erase(arr[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> a;
        all(nums,0,a);
        return a;
    }
};