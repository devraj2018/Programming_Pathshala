class Solution {
public:
    int res=0;
    vector<string> curr;
    bool isSafe(int row,int col,int n)
    {
         int x=row-1,y;
         while(x>=0)
         {
             if(curr[x][col]=='Q') return false;
             x--;
         }
         x=row-1,y=col-1;
        while(x>=0 && y>=0)
          {
             if(curr[x][y]=='Q') return false;
             x--;y--;
          }
          x=row-1,y=col+1;
          while(x>=0 && y>=0 && y<n )
           {
             if(curr[x][y]=='Q') return false;
             x--;y++;
           }
         return true;
      }
    void helper(int row,int n)
      {  
         if(row==n)
         {  res++;
             return;
         }
         for(int c=0;c<n;c++)
            {
               if(isSafe(row,c,n))
                 {
                  curr[row][c]='Q';
                  helper(row+1,n);
                  curr[row][c]='.';
                 }
            }
      }
    int totalNQueens(int n) {
        string temp="";
        for(int i=1;i<=n;i++) temp+=".";
        for(int i=0;i<n;i++) curr.push_back(temp);
        
        helper(0,n);
        return res;
        
    }
};