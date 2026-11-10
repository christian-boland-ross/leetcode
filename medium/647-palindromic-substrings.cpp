class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = 0;
        int size = s.size();

        for(int i = 0; i < size; i++)
        {
            //odd size palindromes
            int left = i, right = i;
            while(left >= 0 && right < size && s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }

            //even size palindromes
            left = i;
            right = i + 1;
            while(left >= 0 && right < size && s[left] == s[right])
            {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};