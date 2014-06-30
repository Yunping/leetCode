/*
Problem: ZigZag Conversion 
Source: https://oj.leetcode.com/problems/zigzag-conversion/
Difficulty: **^
Date: 06/29/2014
Note:
此题独立做出，但中间有过几次逻辑错误，后来修正。
思路如下：
将字符串的索引按照ZigZag方式排列好，然后寻找规律，将重新排列的索引逐个加入到返回字符串中。
首先将索引分组，每组包含两个竖边和一个对角线，如下图中索引
以nRows=4为例，0到9是一组，6到15是另外一组，共三组
然后每组逐行扫描：
- 对于首行和尾行，每组有左右两个元素
- 对于中间各行，每组有左中右三个元素
- 每组中右元素不必计入在内，除非是最后一组，因为当前组的右元素将是下一组的左元素

0           6           12
1       5   7       11  13      17
2   4       8   10      14  16
3           9           15
*/

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        
        int len = s.length();
        int elemsPerGroup = 2 * nRows - 2; // two edge, one diagonal.
        int groups = ceil(((double)len) / elemsPerGroup);
        string ret;
        
        for (int i = 0; i < nRows; ++i) { // iterate each row
            for (int j = 0; j < groups; ++j) { // iterate each group
                int left = j * (2*nRows - 2) + i;
                int right = left + (2*nRows - 2);
                if (left >= len)
                    break;
                ret.push_back(s[left]);
                
                // for rows that are not the first or last, we need to
                // add the middle element
                if (i > 0 && i < nRows - 1) {
                    int middle = right - i * 2;
                    if (middle >= len)
                        break;
                    ret.push_back(s[middle]);
                }
                
                // The last group, we need to add the right edge element
                // in the group
                if (j == groups - 1) {
                    if (right >= len)
                        break;
                    ret.push_back(s[right]);
                }
            }
        }
        
        return ret;
    }
};