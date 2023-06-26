/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* predecessor(TreeNode *current)
        {
            TreeNode *ans = current->left;
            while (ans->right and ans->right != current)
            {
                ans = ans->right;
            }
            return ans;
        }
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                TreeNode *pre = predecessor(curr);
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
                curr = curr->right;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
};