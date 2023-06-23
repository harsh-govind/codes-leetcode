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

        int postindex;

    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int is, int end, unordered_map< int, int> &mp)
    {

        if (is > end) return NULL;

        TreeNode *root = new TreeNode(postorder[postindex]);
        int position = mp[postorder[postindex]];
        postindex--;

        root->right = solve(inorder, postorder, position + 1, end, mp);
        root->left = solve(inorder, postorder, is, position - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
    {

        postindex = inorder.size() - 1;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return solve(inorder, postorder, 0, inorder.size() - 1, mp);
    }
};