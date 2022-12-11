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
        ListNode* sortList(ListNode *head)
        {
            vector<int> temp;

            ListNode *p = head;

            while (p)
            {
                temp.push_back(p->val);
                p = p->next;
            }

            sort(temp.begin(), temp.end());

            p = head;
            int i = 0;
            while (p)
            {
                p->val = temp[i++];
                p = p->next;
            }

            return head;
        }
};