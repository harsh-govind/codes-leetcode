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
class Solution {
public:
    void solve(TreeNode *root, int &ans, int level)
    {
        if(!root) return;
        
        if(!root->left and !root->right)
        {
            ans=min(ans, level+1);
            return;
        }
        
        solve(root->left, ans, level+1);
        solve(root->right, ans, level+1);          
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MAX;
        solve(root, ans, 0);
        
        return ans;
        
    }
};