class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1) fresh++;
                
            }
        }
       
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        
        int time=0;
        int rott=0;
        
        while(!q.empty())
        {
             
            if(fresh==rott) return time;
              time++;
             int size=q.size();
            
               for(int i=1;i<=size;i++)
                 {
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                   
                   for(int j=0;j<4;j++)
                     {
                        int newx=x+dx[j];
                        int newy=y+dy[j];
                       
                       if(newx>=0 && newy>=0 && newx<row && newy<col && grid[newx][newy]==1)
                          {
                           q.push({newx,newy});
                           grid[newx][newy]=2;
                           rott++;
                           
                          }
                       
                     }
                   }
              }
        
        if(rott!=fresh) return -1;
        return time;
        
    }
};