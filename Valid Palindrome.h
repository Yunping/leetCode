/*
Problem: Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/11/2014
Difficulty: *
Review: *
Solution:...
*/
class Solution {
private:
    bool validChar(char s) {
        return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9');
    }
    
    bool equalChar(char c1, char c2) {
        if (c1 >= 'a' && c1 <= 'z')
            c1 -= ('a' - 'A');
        if (c2 >= 'a' && c2 <= 'z')
            c2 -= ('a' - 'A');
        return (c1 == c2);
    }
    
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        
        size_t len = s.length();
        int l = 0, r = len - 1;
        while (l < r) {
            while (!validChar(s[l]) && l < len)
                ++l;
            while (!validChar(s[r]) && r >= 0)
                --r;
                
            if (r < l)
                return true;
            
            if (!equalChar(s[l], s[r]))
                return false;
                
            ++l;
            --r;
        }
        
        return true;
    }
};