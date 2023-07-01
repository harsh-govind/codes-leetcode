/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* findMin(TreeNode *root)
        {
            TreeNode *res = root;
            while (res->left)
            {
                res = res->left;
            }
            return res;
        }
    TreeNode* deleteNode(TreeNode *root, int key)
    {
        if (!root) return nullptr;

        if (root->val == key)
        {
           	//0 child
            if (!root->right and!root->left)
            {
                delete root;
                return nullptr;
            }

           	//1child
           	//right child
            if (root->right and!root->left)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
           	//left child
            if (root->left and!root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

           	//2 child
            if (root->right and root->left)
            {
                TreeNode *mn = findMin(root->right);
                root->val = mn->val;
                root->right = deleteNode(root->right, mn->val);
                return root;
            }
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        return nullptr;
    }
};