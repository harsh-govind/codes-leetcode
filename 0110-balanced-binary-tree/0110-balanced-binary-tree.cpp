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
    pair<bool, int> solve(TreeNode *root)
    {
        if(!root)
        {
            return {true, 0};
        }
        
        pair<bool, int> left=solve(root->left);
        pair<bool, int> right=solve(root->right);
        
        bool op1=left.first;
        bool op2=right.first;
        bool op3=abs(left.second-right.second)<2;
        
        pair<bool, int> res;
        res.first=op1 and op2 and op3;
        res.second=max(left.second, right.second)+1;
        
        return res;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};