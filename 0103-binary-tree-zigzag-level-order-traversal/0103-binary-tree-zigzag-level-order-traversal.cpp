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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root)
 {
    
	if(root == NULL)
        return {};
		
    vector<vector<int> > ans;
    deque<TreeNode*> deque;
    TreeNode* eliminator = new TreeNode(404);
    bool right = true;
    vector<int> temp;
    
    deque.push_back(root);
    deque.push_back(eliminator);
    
    while(deque.size() > 1)
    {   
        if(right)
        {
            TreeNode* front = deque.front();
            
            if(front == eliminator)
            {
                ans.push_back(temp);
                right = !right;
                temp.clear();
            }
            
            else
            {
                temp.push_back(front->val);
                deque.pop_front(); 
                
                if(front->left)
                   deque.push_back(front->left);
                if(front->right)
                   deque.push_back(front->right);      
            }
        }
        
        else
        {
            TreeNode* back = deque.back();
            
            if(back == eliminator)
            {
                ans.push_back(temp);
                right = !right;
                temp.clear();
            }
            
            else
            {
                temp.push_back(back->val);
                deque.pop_back();
                
                if(back->right)
                   deque.push_front(back->right); 
                if(back->left)
                   deque.push_front(back->left);
            }
        }
    }
    ans.push_back(temp);
    return ans;
}
};