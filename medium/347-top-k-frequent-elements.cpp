class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> frequencyList;

        for(int i : nums)
        {
            frequencyList[i]++;
        }

        vector<int> topKList;
        while(topKList.size() < k)
        {
            int maxFrequency = 0;
            int maxElement;
            for(auto it : frequencyList)
            {
                if(it.second > maxFrequency)
                {
                    maxFrequency = it.second;
                    maxElement = it.first;
                }
            }
            topKList.push_back(maxElement);
            frequencyList.erase(maxElement);
        }

        return topKList;
    }
};