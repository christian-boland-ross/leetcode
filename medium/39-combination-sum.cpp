class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, current, 0, result);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<int>& current, int start, vector<vector<int>>& result)
    {
        if(target == 0)
        {
            result.push_back(current);
            return;
        }

        for(int i = start; i < candidates.size(); i++)
        {
            if(candidates[i] > target)
                continue;

            current.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], current, i, result);

            current.pop_back();
        }
    }
};