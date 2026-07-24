class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n == 1){
            return arr[0];
        }
        if(arr[0]<arr[1]){
            return arr[0];
        }else if(arr[n-1]>arr[n-2]){
            return arr[n-1];
        }
        int st = 2, end = n-3;
        while(st<=end){
            int mid = st + (end - st)/2;
            if(mid%2 == 0){
                if(arr[mid-1] == arr[mid]){
                    end = mid-2;
                }else if(arr[mid+1] == arr[mid]){
                    st = mid+2;
                }else{
                    return arr[mid];
                }
            }else{
                if(arr[mid-1]==arr[mid]){
                    st = mid+1;
                }else if(arr[mid+1]==arr[mid]){
                    end = mid-1;
                }else{
                    return arr[mid];
                }
            }
        }
        return -1;
    }
};