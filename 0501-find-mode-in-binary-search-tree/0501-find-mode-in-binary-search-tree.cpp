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
        unordered_map<int, int> m;
    vector<int> ans;
    void fun(TreeNode *p)
    {
        if (p)
        {
            m[p->val]++;
            fun(p->left);
            fun(p->right);
        }
    }
    vector<int> findMode(TreeNode *root)
    {
        fun(root);
        int mx = INT_MIN;

        for (auto &val: m)
        {
            mx = max(mx, val.second);
        }

        for (auto &val: m)
        {
            if (val.second == mx)
            {
                ans.push_back(val.first);
            }
        }

        return ans;
    }
};