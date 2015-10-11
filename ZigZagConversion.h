/*
Problem: ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

==========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/04/2015
Difficulty: **
Review: **
Solution:
以Row＝4为例
0     6       12
1   5 7    11 13    17
2 4   8 10    14 16
3     9       15
按行输出。
此时，有一个重要的数字：gap = 2Row-2，表示每个垂直列之间元素索引的差值
第一行和最后一行的相邻字符索引相差gap
    next_i = cur_i + gap
中间行分两种情况（r为行索引）：
当前元素为垂直列，则下一个元素索引为
    next_i = cur_i + (gap - 2r)
当前元素为非垂直列，则下一个元素为
    next_i = cur_i + 2r
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int len = s.length();
        string ret;
        int gap = 2 * numRows - 2;
        for (int r = 0; r < numRows; ++r) {
            int next_i = 0;
            for (int i = r; i < len; i = next_i) {
                ret.push_back(s[i]);
                if (r == 0 || r == numRows - 1) {
                    next_i = i + gap;
                } else if (i % gap < numRows) {
                    next_i = i + (gap - r * 2);
                } else {
                    next_i = i + r * 2;
                }
            }
        }
        
        return ret;
    }
};