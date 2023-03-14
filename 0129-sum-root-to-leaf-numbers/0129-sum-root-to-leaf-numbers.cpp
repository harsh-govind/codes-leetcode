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
    void bhai(TreeNode* root, vector<int>&a,int n){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            n=n*10+root->val;
            a.push_back(n);
            return ;
        }
        n=n*10+root->val;
        bhai(root->left,a,n);
        bhai(root->right,a,n);
        return ;
    }
    int sumNumbers(TreeNode* root) {
        vector<int>a;
        bhai(root,a,0);
        // direct code for sum below where 0 is starting value of sum;
        return accumulate(a.begin(),a.end(),0);
    }
};