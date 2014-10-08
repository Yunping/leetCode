/*
Problem: Permutation Sequence
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/04/2014
Difficulty: ****
Review: ***
Solution:
    method 1 (康托编码)
    method 2 (利用next_permutation暴力列举)
*/

class Solution {
    // method 1
private:
    int factorial(int n) {
        int ret = 1;
        for (; n > 1; --n)
            ret *= n;
        return ret;
    }
public:
    string getPermutation(int n, int k) {
        string first;
        for (int i = 0; i < n; ++i)
            first.push_back('1'+i);
        if (n == 1) return first;
        --k;
        
        string ret;
        int base = factorial(n-1);
        for (int i = n-1; i > 0; k %= base, base /= i, --i) {
            auto it = next(first.begin(), k / base);
            ret.push_back(*it);
            first.erase(it);
        }
        ret.push_back(first[0]);
        
        return ret;
    }
    
    // method 2 (TLE)
    void nextPermutation(string &str, int n) {
        int i = n - 2, ii = n - 1;
        while (i >= 0) {
            if (str[i] < str[ii]) {
                for (int j = n-1; j > i; --j) {
                    if (str[j] > str[i]) {
                        swap(str[j], str[i]);
                        break;
                    }
                }
                
                break;
            }
            --i;
            --ii;
        }
        
        // reverse [ii, n-1]
        int l = ii, r = n - 1;
        while (l < r)
            swap(str[l++], str[r--]);
    }
    
    string getPermutation_1(int n, int k) {
        string first;
        for (int i = 0; i < n; ++i)
            first.push_back('1'+i);
        
        while (k > 0) {
            nextPermutation(first, n);
            --k;
        }
        
        return first;
    }
};