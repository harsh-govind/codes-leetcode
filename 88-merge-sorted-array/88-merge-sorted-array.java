class Solution {
    public void merge(int[] a, int m, int[] b, int n) {
        if(m==0)
        {
            for(int i=0;i<n;i++)
            {
                a[i]=b[i];
            }
            return;
        }
        if(n==0)
        {
            return;
        }
        int i, j, k;
        i=j=k=0;
        int c[] = new int[m+n];
        while(i<m && j<n)
        {
            if(a[i]<b[j])
            {
                c[k++]=a[i++];
            }
            else if(b[j]<a[i])
            {
                c[k++]=b[j++];
            }
            else
            {
                c[k++]=a[i];
                c[k++]=a[i++];
                j++;
            }
        }
        for(;i<m;i++)
        {
            c[k++]=a[i];
        }
        for(;j<n;j++)
        {
            c[k++]=b[j];
        }
        for(i=0;i<m+n;i++)
        {
            a[i]=c[i];
        }
    }
}