class node
{
    public:
        int data, i, j;

    node(int data, int i, int j)
    {
        this->data = data;
        this->i = i;
        this->j = j;
    }
};
class compare
{
    public:
        bool operator()(node *a, node *b)
        {
            return a->data > b->data;
        }
};
class Solution
{
    public:
        vector<int> smallestRange(vector<vector < int>> &nums)
        {
            priority_queue<node*, vector<node*>, compare> p;

            int mn = INT_MAX, mx = INT_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                mx = max(mx, nums[i][0]);
                mn = min(mn, nums[i][0]);
                p.push(new node(nums[i][0], i, 0));
            }

            int start = mn, end = mx;

            while (p.size() > 0)
            {
                node *temp = p.top();
                p.pop();

                mn = temp->data;
                if (mx - mn < end - start)
                {
                    start = mn;
                    end = mx;
                }

                if (temp->j + 1 < nums[temp->i].size())
                {
                    mx = max(mx, nums[temp->i][temp->j + 1]);
                    p.push(new node(nums[temp->i][temp->j + 1], temp->i, temp->j + 1));
                }
                else
                {
                    break;
                }
            }

            return {
                start,
                end
            };
        }
};