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
    TreeNode *solve(int &preIdx, int inStart, int inEnd, vector<int> &pre, vector<int> &in, unordered_map<int, int> &m, int n)
    {
        if(preIdx>=n or inStart>inEnd)
        {
            return nullptr;
        }
        
        int element = pre[preIdx++];
        int position = m[element];
        
        TreeNode *root=new TreeNode(element);
        root->left=solve(preIdx, inStart, position-1, pre, in, m, n);
        root->right=solve(preIdx, position+1, inEnd, pre, in, m, n);
        
        return root;

    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int, int> m;
        int n=in.size();
        for(int i=0; i<n; i++)
        {
            m[in[i]]=i;
        }
        int preIdx=0;
        return solve(preIdx, 0, n-1, pre, in, m, n);
        
    }
};