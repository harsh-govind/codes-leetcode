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
        ListNode* mergeKLists(vector<ListNode*> &lists)
        {
            map<int, int> m;

            for (int i = 0; i < lists.size(); i++)
            {
                ListNode *ptr = lists[i];
                while (ptr)
                {
                    m[ptr->val]++;
                    ptr = ptr->next;
                }
            }
            //uploaded
            //uploaded
            ListNode *dummy = new ListNode(0);
            ListNode *temp = dummy;
            for (auto &val: m)
            {
                while (val.second > 0)
                {
                    temp->next = new ListNode(val.first);
                    val.second--;
                    temp = temp->next;
                }
            }
            ListNode *head = dummy->next;
            return head;
        }
};
