//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int low, int mid, int high)
    {
        int ans[high-low+1], i=low, j=mid+1, k=0;
        while(i<=mid and j<=high)
        {
            if(arr[i]<arr[j])
            {
                ans[k++]=arr[i++];
            }
            else
            {
                ans[k++]=arr[j++];
            }
        }
        while(i<=mid)
        {
            ans[k++]=arr[i++];
        }
        while(j<=high)
        {
            ans[k++]=arr[j++];
        }
        k=0;
        for(int i=low; i<=high; i++)
        {
            arr[i]=ans[k++];
        }
    }
    public:
    void mergeSort(int arr[], int low, int high)
    {
        if(low<high)
        {
            int mid=low+(high-low)/2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends