/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        int length(ListNode *head)
        {
            int ans = 0;
            while (head)
            {
                ans++;
                head = head->next;
            }
            return ans;
        }
    ListNode* reverseg(int len, ListNode *head, int k)
    {
        if (len < k)
        {
            return head;
        }

        ListNode *p = head, *q = nullptr, *r = nullptr;
        int count = 0;

        while (count < k and p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next=r;
            count++;
        }
        if (p)
        {
            head->next = reverseg(len - k, p, k);
        }
        return q;
    }
    ListNode* reverseKGroup(ListNode *head, int k)
    {
        int len = length(head);
        return reverseg(len, head, k);
    }
};

/*
// SPACE
class Solution
{
    public:
        ListNode* reverseKGroup(ListNode *head, int k)
        {
            vector<ListNode*> temp;
            ListNode *p = head;
            while (p)
            {
                temp.push_back(p);
                p = p->next;
            }

            for (int i = 0; i < temp.size() - temp.size() % k; i += k)
            {
                reverse(temp.begin() + i, temp.begin() + i + k);
            }

            for (int i = 0; i < temp.size()-1; i++)
            {
                temp[i]->next=temp[i+1];
            }
            temp[temp.size()-1]->next=nullptr;

            return temp[0];
        }
};
*/