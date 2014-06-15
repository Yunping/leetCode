/*
Date: 06/14/2014
Difficulty: ***
Note: 
My solution: Using DP. For string s[0, 1, ... i, ...len-1], 
define c(i) is the longest length of the sub stirng s[0, 1,...i].
then c(i+1) = max { c(i), longest length of substr ending with s[i] }
*/
class Solution {
public:
    // calculate the "longest length of substr ending with s[i]"
    int lengthOfLongestSubstringToIndex(string s, int index) {
        if (index < 0) return 0;
        bool hash[256] = { 0 };
        hash[s[index]] = true;
        int ret = 1;
        for (int i = index-1; i >= 0; --i) {
            if (hash[s[i]])
                break;
            hash[s[i]] = true;
            ++ret;
        }
        
        return ret;
    }
    
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len <= 0) return 0;
        int lastLength = 1;
        int maxLength = 1;
        for (int i = 1; i < len; ++i) {
            maxLength = max(lastLength, lengthOfLongestSubstringToIndex(s, i));
            lastLength = maxLength;
        }
        
        return maxLength;
    }
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
    
};

/*
Referred Solution: O(n) time complexity
Using a map to record each char's position, loop the string, calculate
current length and max length.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len <= 1)
            return len;
        int map[256];
        for (int i = 0; i < 256; ++i)
            map[i] = -1;
        int max = 0;
        int temp = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (map[s[i]] == -1 || (i - map[s[i]] > temp))
                ++temp;
            else
                temp = i - map[s[i]];
            
            if (temp > max)
                max = temp;
            map[s[i]] = i;
        }
        
        if (temp > max) max = temp;
        
        return max;
    }
};