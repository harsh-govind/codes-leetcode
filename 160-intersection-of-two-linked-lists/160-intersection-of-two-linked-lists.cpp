/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* getIntersectionNode(ListNode *a, ListNode *b)
        {
           	//first best optimal approach is to count the lenght of the node
           	//second best optiomal approach is to make p1 to p2 if p1 will be null or vice versa
            ListNode *p = a, *q = b;

            while (1)
            {
                if (p == q)
                {
                    return p;
                }
                if (p)
                {
                    p = p->next;
                }
                if (q)
                {
                    q = q->next;
                }
                if (p == nullptr and q == nullptr)
                {
                    return nullptr;
                }
                
                if (!p)
                {
                    p = b;
                }
                if (!q)
                {
                    q = a;
                }
                
            }
            return nullptr;
        }
};