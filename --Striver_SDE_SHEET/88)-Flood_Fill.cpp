int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void dfs(int x,int y,int newC,int oldC,vector<vector<int>> &image)
{
     
    
     image[x][y]=newC;
     for(int i=0;i<4;i++)
     {
         int xx=x+dx[i];
         int yy=y+dy[i];
         if(xx>=0 && yy>=0 && xx<image.size() && yy<image[0].size() && image[xx][yy]==oldC)
         {
             dfs(xx,yy,newC,oldC,image);
         }
     }
     
    
    
    
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
     int oldc=image[x][y];
     if(oldc==newColor) return image;
    
     dfs(x,y,newColor,oldc,image);
    return image;
    
}