class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> freq;
        int need = 0;

        for(int i = 0; i<t.length(); i++){
            freq[t[i]]++;
            need++;
        }

        map<char,int> wfreq;
        string str = "";
        int left = 0; int ans = -1, len = INT_MAX; 

        if(s.length()<t.length()) return "";

        for(int right = 0; right<s.length(); right++){
            wfreq[s[right]]++;

            if(freq.contains(s[right]) && wfreq[s[right]] <= freq[s[right]]){
                need--;
            }

            while(need == 0){

                if(len > right + 1- left){
                    ans = left; len = right + 1 - left;
                }
                wfreq[s[left]]--;

                if(freq.contains(s[left]) && wfreq[s[left]]+1 <= freq[s[left]]){
                    need++;
                }

                if(wfreq[s[left]]==0){
                    wfreq.erase(s[left]);
                }

                left++;
            }
            if(ans != -1) str = s.substr(ans, len);
        }
        return str;
    }
};