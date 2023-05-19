//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node *ans=NULL, *k=NULL, *p=head1, *q=head2;
    
    while(p and q)
    {
        if(p->data < q->data)
        {
            p=p->next;
            continue;
        }
        else if(p->data > q->data)
        {
            q=q->next;
            continue;
        }
        else
        {
            if(!k)
            {
                k=new Node(p->data);
                ans=k;
            }
            else
            {
                Node *temp=new Node(p->data);
                k->next=temp;
                k=k->next;
            }
            
            // while(p->next and p->next->data == p->data)
            //     p=p->next;
                
            // while(q->next and q->next->data == q->data)
            //     q=q->next;
            p=p->next;
            q=q->next;
        }
       
    }
    
    return ans;
}