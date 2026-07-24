class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        int p = 0, i = 0;
        while(i < nums.size()-1){
            if(nums[i] != -101){
                if(nums[i] == nums[i+1]){
                    nums.erase(nums.begin()+i+1);
                    nums.push_back(-101);
                    i--; p++;
                }
            }
            i++;
        }
        int ans = nums.size()-p;
        return ans;
    }
};