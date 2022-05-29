class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        vector<vector<int>>dp(row,vector<int>(col,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++)
        {  for(int j=0;j<col;j++)
              {  if(mat[i][j]==0)
                     {  dp[i][j]=0;
                        q.push({i,j});
                      }
             }
        }
        
        while(!q.empty())
        {  int x=q.front().first;
           int y=q.front().second;
           q.pop();
          
           for(int i=0;i<4;i++)
            { int newx=x+dx[i];
              int newy=y+dy[i];
            
              if(newx>=0 && newy>=0 && newx<row && newy<col && dp[newx][newy]==-1)
               {
                 dp[newx][newy]=dp[x][y]+1;
                 q.push({newx,newy});
               }
            }
          }
        return dp;
        
    }
};

//-----------------  Method-2-----------------------//
