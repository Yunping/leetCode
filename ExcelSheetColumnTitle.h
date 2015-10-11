/*
Problem: Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
    
=================================================================================

Author: Yunping, qufang83@gmail.com
Date: 07/25/2015
Difficulty: **
Review: **^
Solution: (Own) Similiar with 26-base number, but a little bit different.
*/
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n != 0) {
            n = n - 1;
            int c = n % 26;
            result.insert(0, 1, 'A'+c);
            n = n /26;
        }
        return result;
    }
};