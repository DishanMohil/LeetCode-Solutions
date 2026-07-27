class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        map<int,int> m; stack<int> s; int n = t.size(); vector<int> ans;
        s.push(0);

        for(int i = 1; i < n; i++){
            if(t[s.top()]>=t[i]){
                s.push(i); continue;
            }
            while(s.size()>0 && t[s.top()]<t[i]){
                m[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        for(int i = 0; i < n-1; i++){
            ans.push_back(m[i]);
        }
        ans.push_back(0);
        return ans;
    }
};