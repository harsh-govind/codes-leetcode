class Solution
{
    public:
        void invert(int & a)
        {
            if (a == 0)
            {
                a = 1;
            }
            else
            {
                a = 0;
            }
            return;
        }
    vector<vector < int>> flipAndInvertImage(vector<vector < int>> &image)
    {
        int n = image.size();
        for (int i = 0; i < n; i++) {
        
            for(int j=0; j<n;j++)
            {
                invert(image[i][j]);
            }
            
        }
        for (int i = 0; i < n; i++) {
        
            for(int j=0; j<(n)/2;j++)
            {

                swap(image[i][j],image[i][n-j-1] ); 
            }
            
        }
        return image;
    }
};