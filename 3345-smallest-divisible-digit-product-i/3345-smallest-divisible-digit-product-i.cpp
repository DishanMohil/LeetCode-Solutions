class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int ans = 1;
            int copy = n;
            while(copy>0){
                int dig = copy%10;
                copy = copy/10;
                ans *= dig;
            }
            if(ans%t == 0){
                return n;
            }
            n++;
        }
    }
};