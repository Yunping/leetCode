/*
Problem: Subsets II
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/09/2014
Difficulty: **^
Review: ***
Solution: (My Own)
    DFS. To avoid dups, after pop the last item, we need to find a different item to
    start the next dfs.
    画递归图帮助理解
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        
        vector<int> temp;
        vector<vector<int> > ret;
        subsets_dfs(S, 0, temp, ret);
        
        return ret;
    }
    
private:
    void subsets_dfs(vector<int> &S, int index, vector<int> &temp, vector<vector<int> >& ret) {
        int n = S.size();
        if (index == n) {
            ret.push_back(temp);
        } else {
            temp.push_back(S[index]);
            subsets_dfs(S, index+1, temp, ret);
            temp.pop_back();
            int i = index + 1;
            while (i < n && S[i] == S[index])
                ++i;
            subsets_dfs(S, i, temp, ret);
        }
    }
};