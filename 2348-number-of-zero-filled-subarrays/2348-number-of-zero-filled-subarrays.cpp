class Solution {
public:
    long long zeroFilledSubarray(vector<int>& A) {
        int n=A.size();
        long long sum=0;
        long zcount=0;
        for(int i=0;i<n;i++){
            if(!A[i]){
                zcount++;
            }
            else if(A[i] && zcount){
                sum=sum+((zcount)*(zcount+1))/2;
                zcount=0;
            }
        }

        if(zcount){
            sum=sum+((zcount)*(zcount+1))/2;         
        }
        return sum;
    }
};