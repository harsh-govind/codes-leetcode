/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* predecessor(TreeNode *current)
        {
            TreeNode *ans = current->left;
            while (ans->right and ans->right != current)
            {
                ans = ans->right;
            }
            return ans;
        }
    int kthSmallest(TreeNode *root, int &k)
    {
        int i=0;
        int ans=-1;
        TreeNode *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                i++;
                if(i==k) ans=curr->val;
                curr = curr->right;
            }
            else
            {
                TreeNode *pred = predecessor(curr);

                if (!pred->right)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = nullptr;
                    i++;
                    if(i==k) ans=curr->val;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};