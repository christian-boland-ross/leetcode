class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        
        int greatestVolume = 0;
        while(left < right)
        {
            int currentVolume = min(height[left], height[right]) * (right - left);
            greatestVolume = max(greatestVolume, currentVolume);

            if(height[left] < height[right])
                left ++;
            else
                right --;
        }

        return greatestVolume;
    }
};