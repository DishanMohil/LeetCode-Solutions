class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;
        
        int prefix_sum = 0;
        int count = 0;
        
        for (int num : nums) {
            prefix_sum += num;
            
            if (prefix_counts.count(prefix_sum - k)) {
                count += prefix_counts[prefix_sum - k];
            }
            
            prefix_counts[prefix_sum]++;
        }
        
        return count;
    }
};