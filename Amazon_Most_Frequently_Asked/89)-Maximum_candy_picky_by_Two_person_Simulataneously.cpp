class Solution {
public:
    vector<vector<vector<int>>>dp;
    int row,col;
    
    int helper(vector<vector<int>>& grid,int r,int c1,int c2)
    {
        
        if(r==row-1)  // last row
        {
            if(c1==c2) return grid[r][c1];
            else return grid[r][c1]+grid[r][c2];
        }
        
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        
        int ans=INT_MIN;    // Take max of all possible way
        for(int first=-1;first<=1;first++)
        {
            for(int second=-1;second<=1;second++)
            {
                 int new_c1=c1+first;
                 int new_c2=c2+second;
                 int new_r=r+1;
                 if(new_r>= row || new_c1>=col || new_c2>=col || new_c1<0 || new_c2<0) continue;
                
                 if(c1==c2) ans=max(ans,grid[r][c1]+helper(grid,new_r,new_c1,new_c2));  //if Both r at sme thn tk only1 profit
                 else ans=max(ans,grid[r][c1]+grid[r][c2]+helper(grid,new_r,new_c1,new_c2)); // Else take both
                
            }
        }
       return dp[r][c1][c2]=ans;
        
      
    }
    int cherryPickup(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        dp.resize(row,vector<vector<int>>(col,vector<int>(col,-1)));
        
        return helper(grid,0,0,col-1);
        
        
    }
};