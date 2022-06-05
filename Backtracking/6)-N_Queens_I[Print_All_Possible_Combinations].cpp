class Solution {
public:
    vector<vector<string>>res;
    bool isValid(int x,int y,vector<string>&curr,int n)
    { 
         
         for(int i=0;i<=x;i++) if(curr[i][y]=='Q') return false;
      
         int r=x,c=y;
         while(r>=0 && c>=0)
            {   if(curr[r][c]=='Q') return false;
                 r--;c--;
            }
         r=x,c=y;
         while(r>=0 && c<n)
            {
                 if(curr[r][c]=='Q') return false;
                  r--;c++;
            }
        
        return true;
     
    }
    void helper(int curr_row, vector<string>&curr,int n)
    {
        if(curr_row==n)
        {
             res.push_back(curr);
             return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isValid(curr_row,i,curr,n))
            {
                curr[curr_row][i]='Q';
                helper(curr_row+1,curr,n);
                curr[curr_row][i]='.';
            }
        }
     }
    
    vector<vector<string>> solveNQueens(int n) {
       
         string s="";
         for(int i=0;i<n;i++) s+=".";
        
         vector<string>curr(n,s);
         helper(0,curr,n);
         return res;
     }
};