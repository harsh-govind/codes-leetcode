//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *rev(Node *head)
    {
        Node *p=head, *q=NULL, *r=NULL;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
    Node *compute(Node *head)
    {
        if(!head and !head->next)
        {
            return head;
        }
        Node *ans=NULL, *k=NULL;
        head=rev(head);
        Node *prev=head, *p=head->next;
        k=new Node(prev->data);
        ans=k;
        while(p)
        {
            if(p->data >= prev->data)
            {
                k->next=new Node(p->data);
                k=k->next;
                prev=p;
            }
            p=p->next;
        }
        return ans=rev(ans);
            
    }
    
};

/*
class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(!head or !head->next)
        {
            return head;
        }
        while(head and head->next)
        {
            if(head->next->data > head->data)
            {
                head=head->next;
            }
            else
            {
                break;
            }
        }
        
        Node *p=head, *prev=head;
        
        while(p)
        {
            if(p->next and p->next->data > p->data)
            {
                prev->next=p->next;
                prev=p->next;
                p=p->next;
                continue;
            }
            prev=p;
            p=p->next;
        }
        
        return head;
    }
    
};
*/
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends