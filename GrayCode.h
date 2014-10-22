/*
Problem: Gray Code
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/20/2014
Difficulty: **
Review: ***
Solution: (My Own) backtracking
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        grayCode(ret, n);
        
        return ret;
    }
    
private:
    void grayCode(vector<int> &ret, int n) {
        int lastNum = ret.back();
        for (int i = 0; i < n; ++i) {
            int mask = (1<<i);
            int newNum = lastNum ^ mask;
            if (find(ret.begin(), ret.end(), newNum) == ret.end()) {
                ret.push_back(newNum);
                grayCode(ret, n);
                break;
            }
        }
    }
};