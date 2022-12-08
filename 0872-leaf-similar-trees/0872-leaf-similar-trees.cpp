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
        void getLeaf(TreeNode *p, vector<int> &v)
        {
            if (p)
            {
                getLeaf(p->left, v);
                getLeaf(p->right, v);

                if (p->right == nullptr and p->left == nullptr)
                {
                    v.push_back(p->val);
                }
            }
        }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> first, second;

        getLeaf(root1, first);
        getLeaf(root2, second);

        return first == second;
    }
};