class Solution
{
    public:
        vector<int> searchRange(vector<int> &v, int target)
        {
            vector<int> ans;
            if (v.size() == 0)
            {
                cout << "first" << endl;
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            auto it = lower_bound(v.begin(), v.end(), target);
            if (it == v.end())
            {
                cout << "second" << endl;

                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            else if (*it != target)
            {
                cout << "third" << endl;

                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
            }
            auto it2 = upper_bound(v.begin(), v.end(), target);
            it2--;

            if (it2 != v.begin()-1)
            {
                cout << "fourth" << endl;

                if (*it2 == target)
                {
                    cout << "fifth" << endl;

                    ans.push_back(it - v.begin());
                    ans.push_back(it2 - v.begin());
                    return ans;
                }
            }
            cout << "sixth" << endl;

            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
};