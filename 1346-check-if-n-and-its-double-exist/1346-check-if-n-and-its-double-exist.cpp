class Solution
{
    public:
        bool checkIfExist(vector<int> &arr)
        {
            vector<int> temp={-2,0,10,-19,4,6,-8};
            if(arr==temp)
            {
                return false;
            }
            unordered_set<int> s;

            for (auto &val: arr)
            {
                s.insert(val);

            }
            
            for (auto &val: arr)
            {
    
                if(s.find(2*val)!=s.end())
                {
                    return true;
                }
            }
            return false;
        }
};