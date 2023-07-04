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
class BSTIterator {
public:
    int i;
    vector<int> inorder;
    
    BSTIterator(TreeNode* root) {
        getInorder(root);
        i=0;
    }
    void getInorder(TreeNode *root)
    {
        if(!root) return;
        
        getInorder(root->left);
        inorder.push_back(root->val);
        getInorder(root->right);
    }
    int next() {
        if(i>=inorder.size())
        {
            return -1;
        }
        return inorder[i++];
    }
    
    bool hasNext() {
        if(i<=inorder.size()-1)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */