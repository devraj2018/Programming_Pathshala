class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int row=mat.size();
        int col=mat[0].size();
        
        vector<vector<int>>dp(row,vector<int>(col,INT_MAX));
         int dx[4]={-1,1,0,0};
         int dy[4]={0,0,-1,1};
        queue<pair<int,int>>q;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(mat[i][j]==0) {
                    dp[i][j]=0;
                    q.push({i,j});
                }
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
            
                if(xx>=0 && yy>=0 && xx<row && yy<col && dp[xx][yy]>1+dp[x][y])
                {  dp[xx][yy]=1+dp[x][y];
                    q.push({xx,yy});
                }
            }
            
            
        }
        return dp;
    }
};