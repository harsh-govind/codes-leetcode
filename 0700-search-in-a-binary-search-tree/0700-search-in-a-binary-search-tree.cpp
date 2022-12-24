/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* searchBST(TreeNode *root, int val)
        {
            if (!root)
            {
                return nullptr;
            }
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode *curr = q.front();
                q.pop();
                if (val == curr->val)
                {
                    return curr;
                }

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            return nullptr;
        }
};