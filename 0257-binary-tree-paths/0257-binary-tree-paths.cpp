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
        void solve(string current, vector<string>& ans, TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        current += to_string(root->val);

        if (!root->left && !root->right) {
            ans.push_back(current);
            return;
        }

        current += "->";
        solve(current, ans, root->left);
        solve(current, ans, root->right);
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string current = "";
        vector<string> ans;
        solve(current, ans, root);
        return ans;
    }
};