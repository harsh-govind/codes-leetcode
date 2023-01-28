

int peakIndexInMountainArray(int* arr, int n){
    
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]<arr[i])
        {
            return i;
        }
    }
    return -1;
}