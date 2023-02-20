int searchInsert(int* n, int h, int target)
{
    h--;
    if(n[0]>target)
        return 0;
    if(n[h]<target)
        return h+1;
    
    int l=0, mid=0;
    while(l<=h)
    {
        mid = (l+h)/2;
        if(n[mid]==target)
        {
            return mid;
        }
        else if(n[mid]>target)
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
        
    if(n[mid]<target && n[mid+1]>target)
    {
        return mid+1;
    }
    
    return mid;
}