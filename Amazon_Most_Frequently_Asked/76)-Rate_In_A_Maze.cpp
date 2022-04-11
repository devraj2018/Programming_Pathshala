class Solution{
    public:
    vector<string>res;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    char path[4]={'U','D','L','R'};
    
    void dfs(int x,int y,vector<vector<int>> &grid,int n,string &curr_path)
        {
             if(x==n-1 && y== n-1)
                {
                  res.push_back(curr_path);
                  return;
                }
             grid[x][y]=0;  // mark visited
        
             for(int i=0;i<4;i++)
               {
                int newx=x+dx[i];
                int newy=y+dy[i];
             
                if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy]==1)
                  {
                   curr_path.push_back(path[i]);   // Insert That Move
                   dfs(newx,newy,grid,n,curr_path);
                   curr_path.pop_back();  // Remove that bcz that pasth has been complEted
                 }
             
             
                } 
         grid[x][y]=1;    // Backtracking step 
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
    
      string curr_path="";
      if(m[0][0]==0) return res;
      
      dfs(0,0,m,n,curr_path);
      return res;
    }
};