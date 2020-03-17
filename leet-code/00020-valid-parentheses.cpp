class Solution {
public:
    bool isValid(string s) {    
        std::unordered_map<char,char> m;
        m['('] = ')'; m['{'] = '}'; m['['] = ']';
        
        std::stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty() || s[i] != m[st.top()]) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};