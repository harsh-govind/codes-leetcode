class Solution {
public:
    // TIME COMPLEXITY:- O(N)
    // SPACE COMPLEXITY:- O(1)
    #define ll long long
    ll dfs(TreeNode* root,ll sum,ll& ans){
        if(!root)
            return 0;
        ll curr = dfs(root->left,sum,ans) + dfs(root->right,sum,ans) + root->val;
        ans = max(ans,(sum-curr)*curr);
        return curr;
    }
 
    int maxProduct(TreeNode* root) {
        ll ans = 0;
        ll sum = dfs(root,0,ans);
        sum = dfs(root,sum,ans);
        ans%=1000000007;
        return (int)ans;
    }
};