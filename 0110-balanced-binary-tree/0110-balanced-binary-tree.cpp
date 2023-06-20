/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int height(TreeNode *root)
        {
            if (root == nullptr)
            {
                return 0;
            }

            int left = height(root->left);
            int right = height(root->right);

            int ans = max(left, right) + 1;

            return ans;
        }
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        bool op1 = isBalanced(root->left);
        bool op2 = isBalanced(root->right);
        bool op3 = abs(height(root->left) - height(root->right)) < 2;

        return op1 and op2 and op3;
    }
};