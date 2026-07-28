class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Stack holds pairs of {character, consecutive_count}
        stack<pair<char, int>> st;
        
        for (char ch : s) {
            if (!st.empty() && st.top().first == ch) {
                // Increment count for current matching character
                st.top().second++;
            } else {
                // First occurrence of a new character sequence
                st.push({ch, 1});
            }
            
            // If we reached k consecutive characters, drop the sequence
            if (st.top().second == k) {
                st.pop();
            }
        }
        
        // Reconstruct the final string from the stack
        string ans = "";
        while (!st.empty()) {
            auto [ch, count] = st.top();
            st.pop();
            ans.append(count, ch); // Append 'ch' 'count' times
        }
        
        // Reverse to restore original left-to-right order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};