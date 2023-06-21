/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        
        //when we found either p or q
        if(root==p or root==q)
        {
            return root;
        }
        
        TreeNode *left=lowestCommonAncestor(root->left, p, q);
        TreeNode *right=lowestCommonAncestor(root->right, p, q);
        
        if(left and right)
        {
            return root;
        }
        else if(left and !right)
        {
            return left;
        }
        else if(right and !left)
        {
            return right;
        }
        else
        {
            return nullptr;
        }
        
    }
};