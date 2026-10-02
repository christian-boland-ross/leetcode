#include <unordered_map>

class Solution 
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> recentIndex;

        int rear = 0;
        int biggestLength = 0;

        //loop till front pointer hits end
        for (int front = 0; front < s.length(); front++)
        {
            if (recentIndex.count(s[front]))
            {
                rear = max(rear, recentIndex[s[front]] + 1); //when repetition found, move rear pointer forward
            }

            recentIndex[s[front]] = front;

            biggestLength = max(biggestLength, front - rear + 1);
        }

        return biggestLength;
    }
};