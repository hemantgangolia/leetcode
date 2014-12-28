/*
https://oj.leetcode.com/problems/combination-sum/

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
*/
class Solution {
public:
    void helper(vector<int> &candidates, int target, int index, vector<vector<int> > &res, vector<int> &current) {
        if (index >= candidates.size()) {
            return;
        }
        if (target == 0) {
            res.push_back(current);
            return;
        }
        
        helper(candidates, target, index+1, res, current);
        if (target-candidates[index] >= 0) {
            current.push_back(candidates[index]);
            helper(candidates, target-candidates[index], index, res, current);
            current.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, res, temp);
        return res;
    }
};
