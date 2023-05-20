//{ Driver Code Starts
// C program to delete a given key from
// linked list.
#include<bits/stdc++.h>
using namespace std;

/* structure for a node */
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

Node *pre=NULL;

/* Function to delete a given node from the list */
//void deleteNode(struct Node *head, int key);
void deleteNode(Node **head,int data);
void reverse(Node **head);

/* Function to reverse the linked list */
//static void reverse(struct Node** head_ref);

/* Function to insert a node at the beginning of
a Circular linked list */

void push(struct Node **head_ref, int data)
{
	// Create a new node and make head as next
	// of it.

        struct Node *curr = new Node(data);

        curr->next=curr;
    
    	if(*head_ref==NULL)
        {
            *head_ref=curr;
            curr->next=*head_ref;
            pre=*head_ref;
    
        }
        else
        {
            curr->next=*head_ref;
            pre->next=curr;
            pre=pre->next;
    
    
        }
}

/* Function to print nodes in a given
circular linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	if (head != NULL)
	{
		do
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		while (temp != head);
	}
    else
    cout<<"empty"<<endl;

	printf("\n");
}
/* Driver program to test above functions */
int main()
{

	/* Initialize lists as empty */
	int t,a,delnode;
	cin>>t;
	while(t--)
	{
        pre=NULL;
	   Node *head=NULL;
      
        int n;
	    cin>>n;
	    while(n--)
	    {
	        cin>>a;
	        push(&head,a);
	    }    
	/* Created linked list will be 2->5->7->8->10 */
	cin>>delnode;

	deleteNode(&head, delnode);
	
	reverse(&head);

	printList(head);
}
	return 0;
}

// } Driver Code Ends


/* structure for a node 
struct Node
{
	int data;
	struct Node *next;
};
*/

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{
    Node *p=*head;
// Your code goes here
    if(!p)
    {
        return;
    }
    
    if(p->data == key and !p->next )
    {
        head=NULL;
    }
    
    if(p->data ==key)
    {
        Node *q=p;
        while(q->next != p)
        {
            q=q->next;
        }
        q->next=p->next;
        p=p->next;
        return;
    }
    
    Node *q=p,*prev=NULL;
    
    do
    {
        if(q->data == key)
        {
            prev->next=q->next;
            return;
        }
        prev=q;
        q=q->next;
    }while(p!=q);
    
    return;
}

/* Function to reverse the linked list */
void reverse(struct Node** head_ref) {
    if (*head_ref == NULL)
        return;
    
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next;
    
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head_ref);
    
    (*head_ref)->next = prev;
    *head_ref = prev;
}
