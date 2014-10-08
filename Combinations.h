/*
Problem: Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

========================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/06/2014
Difficulty: **
Review: ***
Solution: (My Own) DFS
    Note: in the DFS function, if the elements left can't satisfy the total elements needed,
          the DFS should be returned.
*/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        if (k > n) return ret;
        
        vector<int> result;
        int start = 0;
        combine_dfs(n, k, 1, result, ret);
        
        return ret;
    }

private:  
    void combine_dfs(int n, int k, int index, vector<int> &result, vector<vector<int> > &ret) {
        int current = result.size();
        if (current == k) {
            ret.push_back(result);
            return;
        }
        
        // check whether the elements left is enough.
        int left = n - index + 1;
        if (left+current >= k) {
            for (int i = index; i <= n; ++i) {
                result.push_back(i);
                combine_dfs(n, k, i+1, result, ret);
                result.pop_back();
            }
        }
    }
};