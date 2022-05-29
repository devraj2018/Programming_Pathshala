class Solution {
public:
    vector<vector<bool>>visited;
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    bool isneighbour(vector<vector<char>>& grid,int x,int y,char curr,int pre_x,int pre_y)
    {
         for(int i=0;i<4;i++)
         {    int new_x=x+dx[i];
              int new_y=y+dy[i];
              if(new_x>=0 && new_y>=0 && new_x<n && new_y <m &&grid[new_x][new_y]==curr && visited[new_x][new_y] && (pre_x!=new_x || pre_y !=new_y))
                  return true;
         }
        return false;
        
    }
    bool dfs(int x,int y,vector<vector<char>>& grid,int count,char &curr,int pre_x,int pre_y)
    {
        
        if(count>=4)
        {
            if(isneighbour(grid,x,y,curr,pre_x,pre_y))
                return true;
        }
        visited[x][y]=true;
        
         
        for(int i=0;i<4;i++)
        {  int new_x=x+dx[i];
           int new_y=y+dy[i];
         
             if(new_x>=0 && new_y>=0 && new_x<n && new_y <m &&grid[new_x][new_y]==curr && !visited[new_x][new_y])
             {     
                  if(dfs(new_x,new_y,grid,count+1,curr,x,y))
                      return true;
             }
            
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int row=grid.size(); 
        int col=grid[0].size();
        n=row;
        m=col;
        visited.resize(row,vector<bool>(col,false));
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {    int count=1;
                 if(!visited[i][j])
                 {   char curr=grid[i][j];
                     if(dfs(i,j,grid,count,curr,-1,-1))
                         return true;
                 }
               
            }
        }
        return false;
        
        
    }
};