class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mini = INT_MAX;
        int st;
        int sz = nums.size();
        int end = sz-1;
        if(sz==1 && nums[0]==target){
            return 0;
        }else if(sz==1 && nums[0]!=target){
            return -1;
        }
        for(int i = 0; i < sz; i++){
            if(nums[i]<mini){
                mini = nums[i];
                st = i;
            }
        }
        if(target<=nums[end]){
            while(st<=end){
                int mid = st + (end-st)/2;
                if(target > nums[mid]){
                    st = mid+1;
                }else if(target < nums[mid]){
                    end = mid-1;
                }else{
                    return mid;
                }
            }
        }else{
            end = st-1;
            st = 0;
            while(st<=end){
                int mid = st + (end-st)/2;
                if(target > nums[mid]){
                    st = mid+1;
                }else if(target < nums[mid]){
                    end = mid-1;
                }else{
                    return mid;
                }
            }
        }
        return -1;
    }
};