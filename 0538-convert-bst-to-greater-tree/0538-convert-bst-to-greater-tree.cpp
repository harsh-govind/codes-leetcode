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
    void findInorder(TreeNode *root, vector<int> &inorder)
    {
        if(!root) return;
        
        findInorder(root->left, inorder);
        inorder.push_back(root->val);
        findInorder(root->right, inorder);
    }
    void solve(TreeNode *root, unordered_map<int, int> &m, vector<int> &sum, int n)
    {
        if(!root) return;
        
        root->val+=sum[n-1]-sum[m[root->val]];
        
        solve(root->left, m, sum, n);
        solve(root->right, m, sum, n);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr;
        vector<int> inorder;
        findInorder(root, inorder);
        int n=inorder.size();
        vector<int> sum(n);
        unordered_map<int, int> m;
        sum[0]=inorder[0];
        m[inorder[0]]=0;
        for(int i=1; i<n; i++)
        {
            sum[i]=sum[i-1]+inorder[i];
            m[inorder[i]]=i;
        }
        
        solve(root, m, sum, n);
        return root;
        
    }
};