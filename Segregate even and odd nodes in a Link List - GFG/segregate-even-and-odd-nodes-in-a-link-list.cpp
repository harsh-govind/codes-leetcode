//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(!head or !head->next)
        {
            return head;
        }
        Node *dummy= new Node(0);
        Node *ans=dummy;
        Node *prev=NULL;
        while(head and head->data %2==0)
        {
            prev=head;
            head=head->next;
            prev->next=NULL;
            dummy->next=prev;
            dummy=dummy->next;
        }
        
        Node *p=head;
        while (p)
        {
            if(p->data %2!=0)
            {
                prev=p;
                p=p->next;
            }
            else
            {
                dummy->next=prev->next;
                dummy=dummy->next;
                prev->next=p->next;
                p=p->next;
                dummy->next=NULL;
            }
        }
        dummy->next=head;
        return ans->next;
        
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends