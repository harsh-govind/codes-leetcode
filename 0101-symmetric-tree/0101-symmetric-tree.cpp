class Solution
{
    public:
        bool areMirrorImage(TreeNode *r1, TreeNode *r2)
        {
            if (!r1 && !r2) return true;
            if (!r1 || !r2) return false;

            return ((r1->val == r2->val) && areMirrorImage(r1->left, r2->right) && areMirrorImage(r1->right, r2->left));
        }
    bool isSymmetric(TreeNode *root)
    {
        if (!root) return true;
        //done done done, already done
        return areMirrorImage(root->left, root->right);
    }
};
