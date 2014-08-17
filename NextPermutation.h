/*
Problem: Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1


Author: Yunping, qufang83@gmail.com
Difficulty: ***
Review: ***
Date: 08/17/2014
Solution: 
O(n^2)
1. Find the first pair of numbers with ascending order, say num[i] and num[j], (i < j), 
2. then swap num[i] and num[j]. 
3. Sort the num[i+1] to num[N-1].

*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int N = num.size();
        if (N == 0) return;
        
        pair<int, int> fr = make_pair(-1, N);
        for (int i = N - 1; i > 0; --i) {
            for (int j = i - 1; j > fr.first; --j) {
                if (num[j] < num[i]) {
                    fr.first = j;
                    fr.second = i;
                    break;
                }
            }
        }
        
        if (fr.first != -1) {
            int t = num[fr.first];
            num[fr.first] = num[fr.second];
            num[fr.second] = t;
        }
        
        sort(num.begin() + fr.first + 1, num.end());
    }
};