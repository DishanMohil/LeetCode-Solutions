class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> freq; int need = 0; string ans = ""; int a = -1;
        if(s.length() < t.length()) return "";
        for(int i = 0; i < t.length(); i++){
            freq[t[i]]++;
            need++;
        }
        int l = 0; int len = INT_MAX;
        for(int r = 0; r<s.length(); r++){
            if(freq[s[r]] > 0){
                need--;
            }
            freq[s[r]]--;
            while(need == 0){
                if(len > r+1-l){
                    a = l; len = r+1-l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0){
                    need++;
                }
                l++;
            }
        }
        if(a != -1) ans = s.substr(a,len);
        return ans;
    }
};