======================================================================================================
=====================  O(M*N*M*N) => M*N for FOR loop and M*N for dfs call ===========================
======================================================================================================


class Solution {
public:
    unordered_set<string>res;
    unordered_set<string>valid;
    int row,col;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    void helper(int x,int y,vector<vector<char>>& board,string curr_word)
    {
        
          if(res.size()==valid.size()) return;
          curr_word+= board[x][y];
          if(valid.find(curr_word)!=valid.end()) res.insert(curr_word);
        
          char backtrack= board[x][y];
          board[x][y]='#';
        
          for(int i=0;i<4;i++)
            {
              int xx=x+dx[i];
              int yy=y+dy[i];
             
              if(xx>=0 && yy>=0 && xx<row && yy<col && board[xx][yy]!='#')
              { 
                  helper(xx,yy,board,curr_word);
              }
           }
        
        board[x][y]=backtrack;
        
  }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row=board.size();
        col=board[0].size();
        
        for(auto &s:words) valid.insert(s);
        string curr_word="";
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                
                 helper(i,j,board,curr_word);
                 if(res.size()==valid.size()) break;
                
            }
            if(res.size()==valid.size()) break;
        }
        vector<string>ans;
        for(auto &s:res) ans.push_back(s);
        return ans;
    }
};
