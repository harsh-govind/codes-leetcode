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
        int maxAncestorDiff(TreeNode *root)
        {
            if (!root) return 0;
            int l(root->val), r(l);
            int diff = 0;
            maxDiff(root, l, r, diff);
            return diff;
        }
    void maxDiff(TreeNode *t, int l, int r, int &diff)
    {
        if (!t) return;
        l = min(l, t->val);
        r = max(r, t->val);
        diff = max(r - l, diff);
        maxDiff(t->left, l, r, diff);
        maxDiff(t->right, l, r, diff);
    }
};