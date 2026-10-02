#include <unordered_map>

class Solution 
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = 0;
        int biggestLength = 0;
        unordered_map<char, int> seen;

        int i = 0;
        while(i < s.length() - biggestLength)
        {
            //for each letter after i
            int j = i;
            //if not seen, increment length and add to seen hash table?
            while(j < s.length() && !seen.count(s[j]))
            {
                seen.insert({s[j], j});
                length++;
                j++;
            }
            //if seen
            biggestLength = length > biggestLength ? length : biggestLength;
            //empty hastable
            seen.clear();
            length = 0;
            i++;
        }
        
        return biggestLength;
    }
};