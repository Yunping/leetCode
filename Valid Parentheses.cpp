class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        stack<char> st;
        for (int i = 0; i < len; ++i) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{':
                    st.push(s[i]);
                    break;
                case ')':
                case ']':
                case '}':
                {
                    if (st.empty() || !isPair(st.top(), s[i]))
                        return false;
                    st.pop();
                }
                default:
                    break;
            }
        }
        
        return st.empty();
    }
    
    bool isPair(char l, char r) {
        if (l == '(')
            return r == ')';
        if (l == '[')
            return r == ']';
        if (l == '{')
            return r == '}';
        return false;
    }
};