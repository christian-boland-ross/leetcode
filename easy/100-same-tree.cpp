/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        //base case both are null
        if(p == nullptr && q == nullptr)
            return true;
        //if only one is null, not valid //both is already checked above, one or zero so dont need xor, could use and instead
        //if both are different value, not valid
        if(p != nullptr ^ q != nullptr ||  p->val != q->val)
        {
            return false;
        }
        else
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};