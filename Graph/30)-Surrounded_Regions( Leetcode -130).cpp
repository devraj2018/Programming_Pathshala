class Solution {
public:
     int dx[4]={-1,1,0,0};
     int dy[4]={0,0,1,-1};
     int n, m;
    void dfs(vector<vector<char>>& grid,int x,int y)
    {
         grid[x][y]='#'; 
        
         for(int i=0;i<4;i++)
         {
                int newx=x+dx[i];
                int newy=y+dy[i];
             
                if(newx>=0 && newy>=0 && newx<n&& newy<m && grid[newx][newy]=='O')
                {
                     dfs(grid,newx,newy );
                }
         }
       
        
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][m-1]=='O') dfs(board,i,m-1);
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O') dfs(board,0,j);
            if(board[n-1][j]=='O') dfs(board,n-1,j);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(board[i][j]=='#') board[i][j]='O';
                 else board[i][j]='X';
                
            }
        }
        
        
    }
};