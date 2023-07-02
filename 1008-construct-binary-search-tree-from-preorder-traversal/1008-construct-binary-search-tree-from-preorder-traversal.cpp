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
    TreeNode* solve(vector<int> &preorder, int &i, int mn, int mx)
    {
        if(i>=preorder.size()) return nullptr;
        
        if(preorder[i]<mn or preorder[i]>mx) return nullptr;
        
        TreeNode *node=new TreeNode(preorder[i++]);
        
        node->left=solve(preorder, i, mn, node->val);
        node->right=solve(preorder, i, node->val, mx);
        
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        long long mn=-999999999, mx=999999999;
        int i=0;
        return solve(preorder, i, mn, mx);
    }
};