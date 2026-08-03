class Solution {
public:

    bool istrue(string p){
        string str = p;
        reverse(p.begin(),p.end());
        if(p==str){
            return true;
        }
        return false;
    }

    void solve(vector<vector<string>>& ans, vector<string> part, string s){
        if(s.size()==0){
            ans.push_back(part);
            return;
        }

        for(int i = 0; i<s.size(); i++){
            string p = s.substr(0, i+1);

            if(istrue(p)){
                part.push_back(p);
                solve(ans,part,s.substr(i+1));
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        solve(ans,part,s);
        return ans;
    }
};