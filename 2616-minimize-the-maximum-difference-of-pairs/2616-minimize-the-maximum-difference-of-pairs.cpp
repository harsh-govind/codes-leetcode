class Solution {
public:
    bool valid(vector<int>& nums,int mid, int p){
        //this function is greedily choosing the pairs
        int idx=0;
        int count=0;
        while(idx<nums.size()-1){
            if(nums[idx+1]-nums[idx]<=mid){
                p--;
                idx+=2;//if conscecutive elements are a valid pair then increment index by 2
                if(p==0 ){
                    return true;
                }
            }
            else{
                idx+=1;//if conscecutive elements are a valid pair then increment index by 1
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int maxDiff=nums[nums.size()-1]-nums[0];//maximum difference which can exist
        int start=0;
        int end=maxDiff;
        while(start<=end){
            int mid=(start+end)/2;
            if(valid(nums,mid,p))//if we have found a valid difference,then we try to find a smalller value(as we need to search for minimum)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return start;
    }
};