/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string data;
        prefix(data, root);
        return data;
    }

    void prefix(string& data, TreeNode* current)
    {
        if(current)
        {
            data += to_string(current->val) + ",";
            prefix(data, current->left);
            prefix(data, current->right);
        }
        else
            data += "null,";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        stringstream ss(data);
        return prefixConstruction(ss);
    }

    TreeNode* prefixConstruction(stringstream& ss)
    {
        string value;
        getline(ss, value, ',');

        if(value == "null")
            return nullptr;

        TreeNode* current = new TreeNode(stoi(value));

        current->left = prefixConstruction(ss);
        current->right = prefixConstruction(ss);

        return current;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));