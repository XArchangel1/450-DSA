void helper(int i,int j,vector<vector<int>> &image,int r,int c,int oldcolor,int newColor){
    if(i<0 or j<0 or i>=r or j>=c or image[i][j] != oldcolor){
        return;
    }
    
    image[i][j] = newColor;
    helper(i+1,j,image,r,c,oldcolor,newColor);
    helper(i-1,j,image,r,c,oldcolor,newColor);
    helper(i,j+1,image,r,c,oldcolor,newColor);
    helper(i,j-1,image,r,c,oldcolor,newColor);
}


vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int r = image.size();
    int c = image[0].size();
    int oldcolor = image[x][y];
    if(newColor == oldcolor){
        return image;
    }
    helper(x,y,image,r,c,oldcolor,newColor);
    return image;
}