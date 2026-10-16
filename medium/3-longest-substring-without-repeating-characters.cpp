class Solution 
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int recentIndex[128];

        for (int i = 0; i < 128; i++)
            recentIndex[i] = -1;

        int rear = 0;
        int biggestLength = 0;
        
        //loop till front pointer hits end
        for (int front = 0; front < s.length(); front++)
        {
            if (recentIndex[s[front]] >= rear)
                rear = recentIndex[s[front]] + 1; //when repetition found, move rear pointer forward

            recentIndex[s[front]] = front;

            biggestLength = max(biggestLength, front - rear + 1);
        }

        return biggestLength;
    }
};