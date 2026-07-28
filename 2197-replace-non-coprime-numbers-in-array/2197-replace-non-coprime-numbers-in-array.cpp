class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& n) {
        // stack<int> s;
        vector<int> s;
        for(int a : n){
            if(s.empty()){
                s.push_back(a);
            }else if(!s.empty() && gcd(a,s.back())==1){
                s.push_back(a);
            }else if(!s.empty() && gcd(a,s.back())!=1){
                int l = lcm(a,s.back());
                s.pop_back();
                while(!s.empty() &&gcd(l,s.back())!=1){
                    l = lcm(l,s.back());
                    s.pop_back();
                }
                s.push_back(l);
            }
        }
        // while(!s.empty()){
        //     ans.push_back(s.top());
        // }
        // reverse(ans.begin(),ans.end());
        return s;
    }
};