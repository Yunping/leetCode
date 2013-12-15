/* DPS 
http://blog.sina.com.cn/s/blog_b9285de20101jbtl.html
*/

class Solution {
public:
    vector<vector<string>> allStrs;
    
    void dfs(string s, int start, vector<string> strs) {
        size_t len = s.length();
        if (start > len - 1) {
            allStrs.push_back(strs);
            return;
        }
        
        for (size_t i = 1; i + start <= len; ++i) {
            string sub = s.substr(start, i);
            if (isPalindrome(sub)) {
                strs.push_back(sub);
                dfs(s, start + i, strs);
                strs.pop_back(); // This is important.
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        allStrs.clear();
        vector<string> strs;
        dfs(s, 0, strs);
        return allStrs;
    }
    
    bool isPalindrome(string s) {
        size_t len = s.length();
        if (len > 1) {
            for (size_t i = 0, j = len - 1; i < j; ++i, --j) {
                if (s[i] != s[j])
                    return false;
            }
        }
        return true;
    }
};