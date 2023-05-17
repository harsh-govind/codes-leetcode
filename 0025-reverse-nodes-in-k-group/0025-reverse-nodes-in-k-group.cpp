/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
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

            for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i] << " ";
            }
            cout << endl;
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