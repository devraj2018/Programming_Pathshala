#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
        int fresh=0;
        int r=n;
        int c=m;
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<r;i++)
        {  for(int j=0;j<c;j++)
             {  if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
             }
        }
        if(fresh==0) return 0;
        
        
         int dx[4]={-1,1,0,0};
         int dy[4]={0,0,-1,1};
         int rotted=0;
         int time=0;
        
         while(!q.empty())
          {
            if(fresh==rotted) return time;
            time++;
            int size=q.size();    
            
            for(int i=1;i<=size;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                
                for(int j=0;j<4;j++)
                {
                   int xx=x+dx[j];
                   int yy=y+dy[j];
                   if(xx>=0 && yy>=0 && xx<r && yy<c && grid[xx][yy]==1)
                     {
                        grid[xx][yy]=2;
                        q.push({xx,yy});
                       rotted++;
                     }
                }
                
            }
            
        }

      return -1;
}