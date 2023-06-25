class Solution {
public:
    void solve(vector<vector<int>> &image, int row, int col, int newColor, int originalColor)
    {
        image[row][col]=newColor;
        int m=image.size(), n=image[0].size();
        int r[]={-1, 0, +1, 0}, c[]={0, +1, 0, -1};
        
        for(int i=0; i<4; i++)
        {
            int newRow=row+r[i], newCol=col+c[i];
            if(newRow>=0 and newRow<m and newCol>=0 and newCol<n and image[newRow][newCol]==originalColor and image[newRow][newCol]!=newColor)
            {
                solve(image, newRow, newCol, newColor, originalColor);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];
        
        //solved using dfs
        solve(image, sr, sc, newColor, originalColor);
        
        return image;
    }
};