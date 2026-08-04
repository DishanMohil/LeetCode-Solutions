class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end()); unordered_map<int,int> freq;
        int s = nums[0]; int l = nums[nums.size()-1];
        vector<int> ans;
        for(s; s<=l; s++){
            freq[s]++;
        }
        for(int n : nums){
            freq[n]--;
        }
        for(const auto& [key,value]:freq){
            if(value!=0){
                ans.push_back(key);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};