class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
       
        bool mem[1000][1000] = {false};
        int length = s.length();
        int index = 0, longest = length ? 1 : 0;
        
        for (int i = 0; i < length; ++i) {
            mem[i][i] = true;
            if (i+1 < length && s[i] == s[i+1]) {
                mem[i][i+1] = true;
                index = i;
                longest = 2;
            }
        }
        
        for (int len = 3; len <= length; ++len) {
            for (int i = 0, j = len - 1; j < length; ++i, ++j) {
        		if (mem[i+1][j-1] && s[i] == s[j]) {
        			mem[i][j] = true;
        			if (len > longest) {
        				index = i;
        				longest = len;
        			}
        		}
        	}
        }
        
        return s.substr(index, longest);
    }
    
};