class Solution{
    public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    char dir[4]={'U','D','R','L'};
    
     void dfs(int x,int y,vector<vector<int>> &m, int n,string curr_path,vector<string>&res)
          {
        
             if(x==n-1 && y==n-1)
               {
                   res.push_back(curr_path);
                   return;
               }
          
          
             m[x][y]=0;  // Mark visited
          
            for(int i=0;i<4;i++)
               {
                int xx=x+dx[i];
                int yy=y+dy[i];
              
                char direction=dir[i];
              
                 if(xx>=0 && yy>=0 && xx<n && yy<n && m[xx][yy]==1)
                  {
                    dfs(xx,yy,m,n,curr_path+direction,res);
                  }
              
               }
        
         m[x][y]=1;  // Backtrack
   
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
       
       vector<string>res;
       string curr_path="";
       
       if(m[0][0]==0) return res;
       
        dfs(0,0,m,n,curr_path,res);
        return res;
    }
};