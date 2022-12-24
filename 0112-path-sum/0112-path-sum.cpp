class Solution {
public:

    bool hasPathSum(TreeNode* root, int t) {
        if(root && t == root->val && !root->left && !root->right) return true;
        bool l,r;
        l=r=false;
        if (root ) l = hasPathSum(root->left, t - root->val);
        if (root ) r = hasPathSum(root->right, t - root->val);
        return l | r;
    }
};