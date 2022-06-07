#include<bits/stdc++.h>
    bool isValid(int x,int y,vector<vector<int>>&curr,int n)
    { 
         
         for(int i=0;i<=x;i++) if(curr[i][y]==1) return false;
      
         int r=x,c=y;
         while(r>=0 && c>=0)
            {   if(curr[r][c]==1) return false;
                 r--;c--;
            }
         r=x,c=y;
         while(r>=0 && c<n)
            {
                 if(curr[r][c]==1) return false;
                  r--;c++;
            }
        
        return true;
     
    }
    void helper(int curr_row, vector<vector<int>>&curr,int n, vector<vector<int>>&res)
    {
        if(curr_row==n)
        {
            
             
             vector<int>temp;
             for(int i=0;i<n;i++)
             {
                 for(int j=0;j<n;j++)
                 {
                     temp.push_back(curr[i][j]);
                 }
             }
             res.push_back(temp);
             return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isValid(curr_row,i,curr,n))
            {
                curr[curr_row][i]=1;
                helper(curr_row+1,curr,n,res);
                curr[curr_row][i]=0;
            }
        }
     }
    
vector<vector<int>> solveNQueens(int n) {
        vector<vector<int>>res;
         
    vector<vector<int>>curr(n,vector<int>(n,0));
         helper(0,curr,n,res);
         return res;
}