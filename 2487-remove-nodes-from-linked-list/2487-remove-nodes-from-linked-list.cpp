/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* removeNodes(ListNode *head)
        {
            vector<int> temp;
            ListNode *p = head;

            while (p)
            {
                temp.push_back(p->val);
                p = p->next;
            }

            int n = temp.size(), currMax = INT_MIN;

            for (int i = n - 1; i >= 0; i--)
            {
                currMax = max(currMax, temp[i]);
                if (temp[i] < currMax)
                {
                    temp[i] = -1;
                }
            }
            p=head;
            ListNode *q=head;
            for (int i = 0; i < n; i++)
            {
                if (temp[i] != -1)
                {
                    p->val=temp[i];
                    q=p;
                    p=p->next;
                }
            }
            q->next=nullptr;
            
            return head;
        }
};