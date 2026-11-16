class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> prefixProductList(nums.size());
        int prefixProduct = 1;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            prefixProduct *= nums[i];
            prefixProductList[i] = prefixProduct;
        }

        vector<int> productList(nums.size());
        int suffixProduct = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(i > 0)
                productList[i] = prefixProductList[i-1] * suffixProduct;
            else
                productList[i] = suffixProduct;

            suffixProduct *= nums[i];
        }

        return productList;
    }
};