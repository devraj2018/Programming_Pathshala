class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    bool ans=false;
    void dfs(vector<vector<char>>& board,int x,int y,string word,int &curr_I)
    {
         if(curr_I== word.size() || ans) return;
         if(curr_I== word.size()-1)
            {   ans=true; return;
            }
        
         char ch=board[x][y];
         board[x][y]='#';
         curr_I++;
         
         for(int i=0;i<4;i++)
            {
              int newx=x+dx[i];
              int newy=y+dy[i];
              if(newx>=0 && newy>=0 && newx<board.size() && newy<board[0].size() && board[newx][newy]==word[curr_I])
                 {
                    dfs(board,newx,newy,word,curr_I);
                 }
             }
           curr_I--;
           board[x][y]=ch;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
     int row=board.size(),col=board[0].size();   
    
     for(int i=0;i<row;i++)
        {
          for(int j=0;j<col;j++)
            {
               if(board[i][j]==word[0])
                 {  int curr_I=0;
                    dfs(board,i,j,word,curr_I);
                    if(ans) return true;
                 }
            }
        }
        return false;
     }
};