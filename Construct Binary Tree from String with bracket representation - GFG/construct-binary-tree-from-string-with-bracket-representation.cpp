//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    unordered_map<int, int> mapping(string &str)
    {
        unordered_map<int, int> m;
        stack<int> stk;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]=='(')
            {
                stk.push(i);   
            }
            else if(str[i]==')')
            {
                m[stk.top()]=i;
                stk.pop();
            }
        }
        return m;
    }
    bool c(char a)
    {
        return a>='0' and a<='9';
    }
    Node *solve(string &s, int low, int high, unordered_map<int, int> &m)
    {
        if(low>high) return nullptr;
        
        int num=0;
        while(low<s.size() and c(s[low]))
        {
            num=num*10+(s[low]-'0');
            low++;
        }
        low--;
        Node *root=new Node(num);
        
        int y=-1;
        if(low+1<=high and s[low+1]=='(')
        {
            y=m[low+1];
        }
        
        if(y!=-1)
        {
            root->left=solve(s, low+2, y-1, m);
            root->right=solve(s, y+2, high-1, m);
        }
        return root;
    }
    Node *treeFromString(string str){
        // code here
        unordered_map<int, int>m = mapping(str);
        return solve(str, 0, str.size()-1, m);
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends