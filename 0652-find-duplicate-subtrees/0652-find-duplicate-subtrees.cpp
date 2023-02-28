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
private:
    unordered_map<string, vector<TreeNode*>> cnt;

    string treeHash(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string h = "L" + treeHash(root->left) + "L" + to_string(root->val) + "R" + treeHash(root->right) + "R";
        cnt[h].push_back(root);
        return h;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        treeHash(root);

        vector<TreeNode*> res;
        for (auto& pr : cnt) {
            if (pr.second.size() > 1) {
                res.push_back(pr.second[0]);
            }
        }

        return res;
    }
};
