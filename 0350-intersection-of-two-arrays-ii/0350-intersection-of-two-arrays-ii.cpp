class Solution {
public:
    vector<int> intersectionMerge(vector<int> &v1, vector<int> &v2)
    {   
        vector<int> v;
        int i, j;
        i = j = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] < v2[j])
            {
                i++;
            }
            else if (v1[i] > v2[j])
            {
                j++;
            }   
            else
            {
                v.push_back(v1[i++]);
                j++;
            }
        }
        return v;
    }
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        vector<int> ans = intersectionMerge(v1, v2);
        return ans;
    }
};