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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> list;

        if (!root)
            return list;

        traverse(root, list, 0);

        return list;
    }

    void traverse(TreeNode* root, vector<vector<int>>& list, int level)
    {
        if (!root)
            return;

        if (list.size() <= level)
            list.push_back({});

        list[level].push_back(root->val);

        traverse(root->left, list, level + 1);
        traverse(root->right, list, level + 1);
    }
};