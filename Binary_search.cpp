class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int sum = 0;
        int n = arr.size();
        int ans;
        if(n == 1){
            return arr[0];
        }
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        int st = *max_element(arr.begin(), arr.end()), end = sum;
        while(st<=end){
            int mid = st + (end-st)/2;
            int stu = 1,pages = 0;
            for(int i = 0; i<n; i++){
                if(pages + arr[i]<=mid){
                    pages += arr[i];
                }else{
                    stu++;
                    pages = 0;
                    pages = arr[i];
                }
            }
            if(stu<=k){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
};
