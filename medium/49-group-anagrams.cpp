class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> grouped;

        while(!strs.empty())
        {
            vector<string> newList;
            newList.push_back(strs[0]);
            strs.erase(strs.begin());

            for(int i = 0; i < strs.size(); i++)
            {
                if(isAnagram(newList[0], strs[i]))
                {
                    newList.push_back(strs[i]);
                    strs.erase(strs.begin() + i);
                    i--;
                }
            }

            grouped.push_back(newList);
        }

        return grouped;
    }

    bool isAnagram(const string& a, const string& b)
    {
        unordered_map<char, int> letterCount;

        if(a.size() != b.size())
            return false;

        for(int i = 0; i < a.size(); i++)
            letterCount[a[i]]++;

        for(int i = 0; i < b.size(); i++)
        {
            if(letterCount[b[i]] <= 0)
                return false;

            letterCount[b[i]]--;
        }

        return true;
    }
};