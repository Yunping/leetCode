/*
Date: 06/14/2014
Difficulty: **
Note: Different with tranditional reverse word problems, this one need to remove 
leading or trailing spaces, and also extra spaces between words.

*/
class Solution {
public:
    void reverseWord(string &s, int l, int r) {
        while (l < r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            ++l;
            --r;
        }
    }
    
    // Remove leading and trailling spaces, and extra spaces bwtween words
    void removeSpaces(string &s) {
        int len = s.length();
        int i = 0;
        int j = 0;
        bool wasSpace = true;
        while (i < len) {
            if (s[i] == ' ') {
                if (wasSpace) {
                    ++i;
                    continue;
                }
                wasSpace = true;
            } else
                wasSpace = false;
            s[j++] = s[i++];
        }
        
        // Remove possible last space.
        if (j > 0 && s[j-1] == ' ')
            --j;
        
        // Resize the string.
        s = s.substr(0, j);
    }
    
    void reverseWords(string &s) {
        removeSpaces(s);
        int len = s.length();
        // reverse the entire string
        reverseWord(s, 0, len-1);
        
        // reverse each word.
        int l = 0;
        int r = 1;
        while (r < len) {
            if (s[r] == ' ') {
                reverseWord(s, l, r-1);
                l = r+1;
                r = l+1;
            } else if (r == len-1) {
                reverseWord(s, l, r);
                break;
            } else
                ++r;
        }
    }
};