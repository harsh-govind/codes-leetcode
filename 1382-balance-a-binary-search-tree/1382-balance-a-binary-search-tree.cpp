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
    void findInorder(TreeNode *root, vector<int> &v)
    {
        if(root)
        {
            findInorder(root->left, v);
            v.push_back(root->val);
            findInorder(root->right, v);
        }
    }
    TreeNode* solve(vector<int> &v, int low, int high)
    {
        if(low>high) return nullptr;
        
        int mid=(low+high)/2;
        TreeNode *node=new TreeNode(v[mid]);
        node->left=solve(v, low, mid-1);
        node->right=solve(v, mid+1, high);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> inorder;
        findInorder(root, inorder);
        
        return solve(inorder, 0, inorder.size()-1);
    }
};