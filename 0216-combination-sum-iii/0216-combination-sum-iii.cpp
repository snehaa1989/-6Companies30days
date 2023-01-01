class Solution {
public:
    void helper(int ind, int sum, int n, vector<vector<int>> &res, vector<int> currentCombination, int k)
    {
        if(sum == n && k == 0)
        {
            res.push_back(currentCombination);
            return;
        }
        if(sum > n)
        {
            return;
        }
        for(int i = ind; i <= 9; i++)
        {
            if(i > n) break;
            currentCombination.push_back(i);
            helper(i + 1, sum + i, n, res, currentCombination, k - 1);
            currentCombination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> res;
        
        vector<int> currentCombination;
        
        helper(1, 0, n, res, currentCombination, k);
        return res;
        
    }
};