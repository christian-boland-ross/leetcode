class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n+1);
        for(int i = 0; i <= n; i++)
        {
            int n = i;
            int setBits = 0;
            while(n!= 0)
            {
                n = n & (n-1);
                setBits++;
            }
            ans[i] = setBits;
        }
        return ans;
    }
};