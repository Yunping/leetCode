/*
Problem: Combination Sum II 
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6]

=============================================================================================

Author: Yunping, qufang83@gmail.com
Date: 8/30/2014
Difficulty: ***^
Review: ***^
Solution:
Similiar with the problem "Combination Sum I", combine numbers in C recursively. The different is, 
each number in C may only be used once. So the next recursion must start from the next index, 
not the same index.
Note how to avoid dup results. I didn't ignore dups in the first two submissions.

*/
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int> temp;
        vector<vector<int> > ret;
        
        doCombinationSum2(num, 0, target, temp, ret);
        
        return ret;
    }
    
private:
    void doCombinationSum2(vector<int> &num, int start, int target, vector<int> &result, vector<vector<int> > &ret)
    {
        if (target == 0) {
            if (!result.empty())
                ret.push_back(result);
            return;
        }
        
        for (int i = start; i < num.size(); ++i) {
            if (num[i] > target)
                break;
            if (i == start || num[i] != num[i-1]) { // ignore dups
                result.push_back(num[i]);
                doCombinationSum2(num, i+1, target-num[i], result, ret);
                result.pop_back();
            }
        }
    }
};