/*
Problem: Subsets
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

=============================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/09/2014
Difficulty: **
Review: ***
Solution: (My Own)
    DFS
相关题目：Cracking the code interview
    http://hawstein.com/posts/8.3.html
    
*/
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;
        vector<int> result;
        sort(S.begin(), S.end());
        
        subsets_dfs(S, 0, result, ret);
        return ret;
    }
    
private:
    void subsets_dfs(vector<int> &S, int index, vector<int> &result, vector<vector<int> > &ret) {
        int n = S.size();
        if (index == n) {
            ret.push_back(result);
            return;
        }
        
        result.push_back(S[index]);
        subsets_dfs(S, index+1, result, ret);
        result.pop_back();
        subsets_dfs(S, index+1, result, ret);
    }
};