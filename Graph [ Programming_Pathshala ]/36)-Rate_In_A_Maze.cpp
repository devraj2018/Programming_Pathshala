class Solution{
    public:
     int size;
    vector<string>res;
    vector<vector<bool>>vis;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    char dir[4]={'U','D','L','R'};
    
    void dfs(vector<vector<int>> &grid,string curr_path,int x,int y)
    {
        
         if(x==size-1 && y==size-1)
         {
              res.push_back(curr_path);
              return;
             
         }
         vis[x][y]=true;
         
         for(int i=0;i<4;i++)
         {
              int new_x=x+dx[i];
              int new_y=y+dy[i];
              
              char d=dir[i];
              
              if(new_x>=0 && new_y>=0 && new_x<size && new_y<size && vis[new_x][new_y]==false && grid[new_x][new_y]==1 )
               {
                   curr_path.push_back(d);
                   dfs(grid,curr_path,new_x,new_y);
                   
                   curr_path.pop_back();
               }
             
         }
         vis[x][y]=false;
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
      string curr_path="";
      vis.resize(n,vector<bool>(n,false));
      size=n;
      dfs(m,curr_path,0,0);
      
      if(m[0][0]==0) return {};
      return res;
        
    }
};