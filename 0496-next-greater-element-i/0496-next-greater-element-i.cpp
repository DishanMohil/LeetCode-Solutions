class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2) {
        stack<int> s; int n = num2.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            s.push(num2[i]);
        }
        for(int i : num1){
            stack<int> s1(s);
            int a = -1;
            if(i == s1.top()) ans.push_back(-1);
            while(!s1.empty() && s1.top()!=i){
                if(s1.top()>i) a = s1.top();
                else a = max(s1.top(),a);
                s1.pop();
                if(s1.top() == i && a>i) ans.push_back(a);
                else if(s1.top()==i && a<=i) ans.push_back(-1);
            }
        }
        return ans;
    }
};