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
        unordered_set<int> s;
    bool ans = false;
    void check(TreeNode *p, int k)
    {
        if (p)
        {
            int curr = p->val;
            int req = k - curr;
            if (s.find(req) != s.end())
            {
                ans = true;
                return;
            }
            s.insert(curr);
            check(p->left, k);
            check(p->right, k);
        }
    }
    bool findTarget(TreeNode *root, int k)
    {
        check(root, k);
        return ans;
    }
};