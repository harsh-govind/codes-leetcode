class Solution
{
    public:
        bool uniqueOccurrences(vector<int> &arr)
        {
            unordered_map<int, int> s;

            for (auto &val: arr)
            {
                s[val]++;
            }

            unordered_set<int> ss;
            
            for(auto &val:s)
            {
                if(ss.find(val.second)!=ss.end())
                {
                    return false;
                }
                
                ss.insert(val.second);
            }
            
            return true;
        }
};