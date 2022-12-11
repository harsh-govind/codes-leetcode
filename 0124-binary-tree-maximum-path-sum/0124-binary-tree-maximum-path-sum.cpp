class Solution {
public:
    //STREAKS
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int l = max(dfs(root->left),0);
        int r = max(dfs(root->right),0);
        ans = max(ans,root->val+l+r);
        return max(l+root->val,r+root->val);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};