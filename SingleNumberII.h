/*
Problem: Single Number II
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

=================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/09/2014
Difficulty: ***
Review: ***^
Solution: (Referred to others)
    count one in each bit for every A[i]. If count[i] % 3 != 0, the one must be
    in the single number.
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        vector<int> oneCount(sizeof(int) * 8, 0);
        for (int i = 0; i < n; ++i) {
            int a = A[i];
            for (int j = 0; j < oneCount.size(); ++j) {
                if (1 & (a >> j))
                    ++oneCount[j];
            }
        }
        
        int single = 0;
        for (int i = 0; i < oneCount.size(); ++i) {
            if (oneCount[i] % 3) {
                single |= (1 << i);
            }
        }
        
        return single;
    }
};