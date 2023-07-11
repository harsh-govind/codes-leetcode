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
    void getPath(TreeNode *root, vector<TreeNode*> &path, vector<TreeNode*> current, TreeNode *target)
    {
        if(!root) return;
        
        if(root==target)
        {
            current.push_back(root);
            path=current;
            return;
        }
        
        current.push_back(root);
        getPath(root->left, path, current, target);
        getPath(root->right, path, current, target);
        current.pop_back();
    }
    void find(TreeNode *root, TreeNode *never, int level, int k, vector<int> &ans)
    {
        if(!root or root==never) return;
        
        if(level==k)
        {
            ans.push_back(root->val);
            return;
        }
        
        find(root->left, never, level+1, k, ans);
        find(root->right,never,  level+1, k, ans);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        vector<TreeNode*> path, current;
        getPath(root, path, current, target);
        
        //if(k>path.size()) return ans;
        int n=path.size();
        int start=n-k;
        int v=1;
        find(path[n-1], nullptr,0, k, ans);
        for(int i=n-2; i>=0 and n>=start; i--)
        {
            cout<<path[i]->val<<" ";
            find(path[i], path[i+1], 0,k-v, ans);
            v++;
        }
        return ans;
    }
};

/*
    void solveTree(TreeNode *root, int level, int k, vector<int> &ans)
    {
        if(!root) return;
        
        if(level==k)
        {
            ans.push_back(root->val);
            return;
        }
        
        solveTree(root->left, level+1, k, ans);
        solveTree(root->right, level+1, k, ans);
    }

*/