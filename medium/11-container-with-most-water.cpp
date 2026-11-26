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

            if (height[left] < height[right])
            {
                int currentHeight = height[left];

                while (left < right && height[left] <= currentHeight)
                    left++;
            }
            else
            {
                int currentHeight = height[right];

                while (left < right && height[right] <= currentHeight)
                    right--;
            }
        }

        return greatestVolume;
    }
};