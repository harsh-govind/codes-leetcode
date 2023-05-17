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
        ListNode* reverseKGroup(ListNode *head, int k)
        {
            vector<int> temp;
            ListNode *p = head;
            while (p)
            {
                temp.push_back(p->val);
                p = p->next;
            }

            for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < temp.size() - temp.size() % k; i += k)
            {
                reverse(temp.begin() + i, temp.begin() + i + k);
            }

            int i=0;
            p=head;
            while(p)
            {
                p->val=temp[i++];
                p=p->next;
            }

            return head;
        }
};