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
class info{
    public:
    int mx;
    int mn;
    int sum;
    bool isBST;
};
class Solution {
public:
    info solve(TreeNode *root, int &ans)
    {
        if(!root)
        {
            return {INT_MIN, INT_MAX, 0, true};
        }
        
        info left=solve(root->left, ans);
        info right=solve(root->right, ans);
        
        info current;
        
        current.mx=max(root->val, right.mx);
        current.mn=min(root->val, left.mn);
        current.sum=left.sum+right.sum+root->val;
        
        if(left.isBST and right.isBST and root->val > left.mx and root->val<right.mn)
        {
            current.isBST = true;
        }
        else
        {
            current.isBST = false;
        }
        
        if(current.isBST)
        {
            ans=max(ans, current.sum);
        }
        
        return current;
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
    	solve(root, ans);
    	return ans;
    }
};