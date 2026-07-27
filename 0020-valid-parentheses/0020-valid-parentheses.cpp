class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp = {{'(',')'},   {'{','}'},  {'[',']'}};
        stack<char> stk;
        for(char ch:s){
            if(mp.contains(ch)){
                stk.push(ch);
            }else{
                if(stk.empty()) return false;
                else if(mp[stk.top()]!=ch) return false;
                else{
                    stk.pop();
                }
            }
        }
        if(stk.empty()) return true;
        else return false;
    }
};