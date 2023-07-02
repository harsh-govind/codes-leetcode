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
    vector<int> merge(vector<int> &a, vector<int> &b)
    {
        int m=a.size(), n=b.size(), i=0, j=0;
        vector<int> c;
        while(i<m and j<n)
        {
            if(a[i]<b[j])
            {
                c.push_back(a[i++]);
            }
            else
            {
                c.push_back(b[j++]);
            }
        }
        while(i<m)
        {
            c.push_back(a[i++]);

        }
        
        while(j<n)
        {
            c.push_back(b[j++]);
        }
        
        return c;
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        findInorder(root1, a);
        findInorder(root2, b);
        
        return merge(a, b);
    }
};