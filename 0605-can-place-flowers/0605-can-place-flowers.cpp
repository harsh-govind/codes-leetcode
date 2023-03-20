class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int m=v.size();
        v.push_back(0);
        v.insert(v.begin(),0);
        for(int i=1;i<m+1;i++)
        {
            if(v[i-1]==0 and v[i]==0 and v[i+1]==0)
            {
                n--;
                v[i]=1;
            }
        }
        return n<=0;
    }
};