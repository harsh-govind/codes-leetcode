class Solution
{
    public:
        bool areNumbersAscending(string s)
        {
            int n = s.length();
            vector<int> v;

            for (int i = 0; i < n; i++)
            {

                if (s[i] >= '0'
                    and s[i] <= '9')
                {
                    string temp = "";
                    while (s[i] >= '0'
                        and s[i] <= '9')
                    {
                        temp += s[i];
                        i++;
                    }
                    v.push_back(stoi(temp));
                }
            }
            for (auto &val: v)
            {
                cout << val << " ";
            }
            cout << endl;

            auto i2 = adjacent_find(v.begin(), v.end(), greater_equal<int> ());
            if (i2 == v.end())
            {
               return true;
            }
            else
            {
               return false;
            }
            cout<<"last"<<endl;
            return false;
        }
};