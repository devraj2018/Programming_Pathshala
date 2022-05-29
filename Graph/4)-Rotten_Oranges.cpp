class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_count=0;
        int rotten_count=0;
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++)
        {
          for(int j=0;j<col;j++)
            {
                 if(grid[i][j]==2)  q.push({i,j});
                 else if(grid[i][j]==1) fresh_count++;
            }
        }
        int ans=0;
        while(!q.empty())
        {    
            if(fresh_count==rotten_count)
                return ans;
            ans++;
            
            int size=q.size();
            for(int s=0;s<size;s++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
           
                for(int i=0;i<4;i++)
                   { int new_x=x+dx[i];
                     int new_y=y+dy[i];
                
                     if(new_x>=0 && new_y>=0 && new_x<row && new_y<col && grid[new_x][new_y]==1)
                       {
                        grid[new_x][new_y]=2;
                        q.push({new_x,new_y});
                        rotten_count++;
                       }
                 
                   }
            }
            
            
        } 
       return rotten_count==fresh_count?ans:-1;
       
       
    }
};