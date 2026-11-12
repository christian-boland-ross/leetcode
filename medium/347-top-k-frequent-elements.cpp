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

        priority_queue<pair<int, int>> maxHeap;

        for(auto it : frequencyList)
        {
            maxHeap.push({it.second, it.first});
        }

        vector<int> topKList;

        while(k--)
        {
            topKList.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return topKList;
    }
};