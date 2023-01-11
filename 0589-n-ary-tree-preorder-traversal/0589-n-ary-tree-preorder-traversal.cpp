/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    public:
        vector<int> ans;
    void po(Node *root)
    {
        if (root)
        {
            ans.push_back(root->val);

            for (int i = 0; i < (root->children).size(); i++)
            {
                po(root->children[i]);
            }
        }
    }
    vector<int> preorder(Node *root)
    {
        po(root);
        return ans;
    }
};