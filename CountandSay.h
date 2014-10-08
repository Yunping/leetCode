/*
Problem: Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

===========================================================================

Author: Yunping, qufang83@gmail.com
Date: 08/23/2014
Difficulty: **
Review: ****
Solution: Convert one by one. Not good enough. Is there a better solution?

*/
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            const char *p = s.c_str();
            int curCount = 0;
            string d;
            while (true) {
                if (*p == '\0' || (p != s.c_str() && *p != *(p-1))) {
                    char numStr[32];
                    sprintf(numStr, "%d%c", curCount, *(p-1));
                    d += numStr;
                    curCount = 1;
                    
                    if (*p == '\0')
                        break;
                } else
                    ++curCount;
                ++p;
            }
            s = d;
        }
        
        return s;
    }
};