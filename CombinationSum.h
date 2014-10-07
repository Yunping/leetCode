/*
Problem: Combination Sum
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3]

=============================================================================

Author: Yunping, qufang83@gmail.com
Date: 08/27/2014
Difficulty: ***^
Review: ****
Solution: (my solution)
1. Sort and remove dups by using a set.
2. DFS: Try every candidates recursively.

This problem is similiar with "coins sum".
*/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // using a set, in order to sort and make unique to avoid dups.
        set<int> numbers(candidates.begin(), candidates.end());
        vector<int> sorted(numbers.begin(), numbers.end());
        
        vector<int> temp;
        vector<vector<int> > ret;
        combinationSum_dfs(sorted, target, 0, temp, ret);
        
        return ret;
    }

private:  
    bool combinationSum_dfs(vector<int> & candidates, int target, int previousIndex, 
                          vector<int> &result, vector<vector<int> > &ret) {
        if (target == 0) {
            if (!result.empty())
                ret.push_back(result);
            return true;
        }
        
        // Start from previousIndex of candidates to avoid duplicate results.
        for (int i = previousIndex; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                // the following candidates are all greater then target, 
                // so terminate the loop.
                break;
            } else {
                result.push_back(candidates[i]);
                bool find = combinationSum_dfs(candidates, target - candidates[i], i, result, ret);
                result.pop_back();
                if (find)
                    break;
            }
        }
        
        return false;
    }
};