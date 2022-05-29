class Solution {
public:
    bool ans=false;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
   
    void dfs(vector<vector<char>>& board,string word,int curr_I,int x,int y,int row,int col)
    {
         if(ans) return;
         if(curr_I==word.length()-1){
             ans=true;
             return;
         }
        
         char backtrack=board[x][y];
         board[x][y]='#';
         curr_I++;
        
         for(int i=0;i<4;i++)
            {
            int xx=x+dx[i];
            int yy=y+dy[i];
            
            if(xx>=0 && yy>=0 && xx<row && yy<col && board[xx][yy]==word[curr_I])
                  dfs(board,word,curr_I,xx,yy,row,col);
           }
        board[x][y]=backtrack;
         
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