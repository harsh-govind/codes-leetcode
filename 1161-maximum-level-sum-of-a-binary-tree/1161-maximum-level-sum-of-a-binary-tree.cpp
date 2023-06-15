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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* node;
        int n,s=0,x=1,y=INT_MIN,z;
        q.push(root);
        while(!q.empty()){
            n = q.size();
            s = 0;
            while(n--){
                node = q.front();q.pop();
                s += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(s>y){
                y = s;
                z = x;
            }
            x++;
        }
        return z;
    }
};