//think out by myself. Do not always try those "advanced" methods.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const char *str = s.c_str();
        if (strlen(str) == 0) return 0;
        
        int ret = 0;
        int p1 = 0, p2 = 1;
        int len = s.length();
        while (p2 < len) {
            int temp;
            if (hasRepeat(s, p1, p2, temp)) {
                if (ret < p2 - p1)
                    ret = p2 - p1;
                p1 = temp + 1;
            }
            ++p2;
        }
        
        if (ret < p2-p1)
            ret = p2 - p1;
        
        return ret;
    }
    
    bool hasRepeat(string s, int from, int to, int &temp) {
        const char *str = s.c_str();
        char target = str[to];
        for (int i = from; i < to; ++i) {
            if (str[i] == target) {
                temp = i;
                return true;
            }
        }
        
        return false;
    }
};


// 参考了其他答案:
// http://leetcode.com/2011/05/longest-substring-without-repeating-characters.html
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool exists[256] = { false };
        int len = s.length();
        int i = 0, j = 0;
        int maxLen = 0;
        while (j < len) {
            if (exists[(int)s[j]]) {
                maxLen = max(maxLen, j - i);
                while (s[i] != s[j]) {
                    exists[(int)s[i]] = false;
                    ++i;
                }
                ++i;
                ++j;
            } else {
                exists[(int)s[j]] = true;
                ++j;
            }
        }
        
        maxLen = max(maxLen, j - i);
        
        return maxLen;
    }
};