/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* insertIntoBST(TreeNode *root, int val)
        {
            if (!root)
            {
                root = new TreeNode(val);
                return root;
            }
            TreeNode *p = root, *prev = root;
            while (p)
            {
                if (p->val > val)
                {
                    prev = p;
                    p = p->left;
                }
                else
                {
                    prev = p;
                    p = p->right;
                }
            }

            cout << prev->val;
            TreeNode *k = new TreeNode(val);
            if (prev->val > val)
            {
                prev->left = k;
            }
            else
            {
                prev->right = k;
            }
            return root;
        }
};