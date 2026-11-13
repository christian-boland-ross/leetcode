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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int preIndex = 0;

        return build(preorder, inorder, preIndex, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd)
    {
        if(inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex++;

        int i = inStart;
        while(i <= inEnd && inorder[i] != root->val)
        {
            i++;
        }

        root->left = build(preorder, inorder, preIndex, inStart, i - 1);

        root->right = build(preorder, inorder, preIndex, i + 1, inEnd);

        return root;
    }

};