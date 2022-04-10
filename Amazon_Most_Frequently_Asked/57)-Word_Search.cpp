class Solution {
public:
    bool ans=false;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(vector<vector<char>>& board, string word,int curr_I,int x,int y,int &row,int &col)
    {
         if(ans) return;     // To avoid further recursive calls
         if(curr_I== word.size()-1)
         {
             ans=true;
             return;
         }
        
         char chr=board[x][y];
         board[x][y]='#';
        
         for(int i=0;i<4;i++)
         {
             int newx=x+dx[i];
             int newy=y+dy[i];
             
             if(newx>=0 && newy>=0 && newx<row && newy<col && board[newx][newy]==word[curr_I+1])
             {
                 dfs(board,word,curr_I+1,newx,newy,row,col);
             }
          }
        
        board[x][y]=chr;
     }
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(word[0]==board[i][j])
                {
                    dfs(board,word,0,i,j,row,col);
                    if(ans) return true;
                }
                
            }
        }
        return false;
        
    }
};