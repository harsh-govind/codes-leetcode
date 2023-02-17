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
        int minDiffInBST(TreeNode *root)
        {
            int res = INT_MAX, pre = -1;
            check(root, pre, res);
            return res;
        }

    void check(TreeNode *root, int &pre, int &res)
    {
        if (root)
        {
            check(root->left, pre, res);
            if (pre != -1)
            {
                res = min(res, root->val - pre);
            }
            pre = root->val;
            check(root->right, pre, res);
        }
    }
};