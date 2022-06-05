class Solution {
public:
  // Similar to 0-1 Matrix and here res matrix is already initalized from start
     
    void wallsAndGates(vector<vector<int>> &rooms) {
       int row=rooms.size();
       int col=rooms[0].size();
       int dx[4]={-1,1,0,0};
       int dy[4]={0,0,-1,1};

       queue<pair<int,int>>q;
       for(int i=0;i<row;i++)
       {
           for(int j=0;j<col;j++)
           {
                 if(rooms[i][j]==0) q.push({i,j});

           }
       }

       while(!q.empty())
       {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int xx=x+dx[i];
                int yy=y+dy[i];
            
                if(xx>=0 && yy>=0 && xx<row && yy<col && rooms[xx][yy]>1+rooms[x][y])
                {   rooms[xx][yy]=1+rooms[x][y];
                     q.push({xx,yy});
                }
            }
       }

    }
};