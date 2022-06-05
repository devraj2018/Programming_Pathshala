class Solution {
public:
      int dx[4]={-1,1,0,0};
      int dy[4]={0,0,-1,1};
      int row,col;
     
      void dfs(int x,int y,vector<vector<char>>& grid)
         {
            grid[x][y]='#';
            for(int i=0;i<4;i++)
                 {
                    int xx=x+dx[i];
                    int yy=y+dy[i];
                    if(xx>=0 && yy>=0 && xx<row && yy<col && grid[xx][yy]=='O')
                         dfs(xx,yy,grid);
            
                 }
         }
    
     void solve(vector<vector<char>>& board) {
        row=board.size();
        col=board[0].size();
         
        for(int i=0;i<row;i++)
        {
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][col-1]=='O') dfs(i,col-1,board);
        }
        for(int j=0;j<col;j++)
        {
            if(board[0][j]=='O') dfs(0,j,board);
            if(board[row-1][j]=='O') dfs(row-1,j,board);
        }
         
        for(int i=0;i<row;i++)
          {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='#') board[i][j]='O';
                else board[i][j]='X';
                
            }
        }
        
    }
};