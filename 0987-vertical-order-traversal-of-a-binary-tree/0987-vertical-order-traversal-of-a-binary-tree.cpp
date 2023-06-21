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
        vector<vector < int>> verticalTraversal(TreeNode *root)
        {
            vector<vector < int>> ans;
            if (!root)
            {
                return ans;
            }
           	// horizontal distance -> level -> nodes
            map<int, map<int, multiset< int>>> m;

           	// node, horizontal distance -> level
            queue<pair<TreeNode*, pair<int, int>>> q;

            q.push(make_pair(root, make_pair(0, 0)));

            while (!q.empty())
            {
                pair<TreeNode*, pair<int, int>> temp = q.front();
                q.pop();

                TreeNode *node = temp.first;
                int hrdst = temp.second.first, lvl = temp.second.second;

                m[hrdst][lvl].insert(node->val);

                if (node->left)
                {
                    pair<TreeNode*, pair<int, int>> p;
                    p.first = node->left;

                    p.second.first = hrdst - 1;
                    p.second.second = lvl + 1;

                    q.push(p);
                }

                if (node->right)
                {
                    pair<TreeNode*, pair<int, int>> p;
                    p.first = node->right;

                    p.second.first = hrdst + 1;
                    p.second.second = lvl + 1;
                    q.push(p);
                }
            }

            for (auto &i: m)
            {
                vector<int> col;
                for (auto &j: i.second)
                {
                    col.insert(col.end(), j.second.begin(), j.second.end());
                }
                ans.push_back(col);
            }

            return ans;
        }
};