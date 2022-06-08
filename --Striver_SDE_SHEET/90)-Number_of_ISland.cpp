int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={-1,-1,-1,0,0,1,1,1};
void dfs(int x,int y,int **arr,int n,int m)
{
     
    
     arr[x][y]=0;
     for(int i=0;i<8;i++)
     {
         int xx=x+dx[i];
         int yy=y+dy[i];
         if(xx>=0 && yy>=0 && xx<n&& yy<m && arr[xx][yy]==1)
         {
             dfs(xx,yy,arr,n,m);
         }
     }
     
    
}
int getTotalIslands(int** arr, int n, int m)
{
   int count=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(arr[i][j]==1)
           {
               count++;
               dfs(i,j,arr,n,m);
           }
       }
   }
    return count;
}
