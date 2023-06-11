/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    public:
        Node* copyRandomList(Node *head)
        {
            if (!head) return head;

            Node *p = head;

            while (p)
            {
                Node *temp = p->next;
                p->next = new Node(p->val);
                p->next->next = temp;
                p = temp;
            }

            p = head;
            while (p)
            {
                if (p->random)
                {
                    p->next->random = p->random->next;
                }
                p = p->next->next;
            }

            p = head;
            Node *newHead = p->next;

            while (p)
            {
                Node *temp = p->next;
                if (p->next)
                    p->next = p->next->next;
                if (temp->next)
                    temp->next = temp->next->next;
                p = p->next;
            }
            return newHead;
        }
};