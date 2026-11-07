class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<int> emptyList;
        return backtrack(candidates, target, emptyList, 0);
    }

    vector<vector<int>> backtrack(vector<int>& candidates, int target, vector<int> previous, int start)
    {
        if(target == 0)
            return {previous};
        vector<vector<int>> combinationList;
        for(int i = start; i < candidates.size(); i++)
        {
            if(target-candidates[i] >= 0)
            {
                vector<int> next = previous;
                next.push_back(candidates[i]);

                vector<vector<int>> results = backtrack(candidates, target - candidates[i], next, i);

                combinationList.insert(combinationList.end(), results.begin(), results.end());
            }
        }
        return combinationList;
    }
};