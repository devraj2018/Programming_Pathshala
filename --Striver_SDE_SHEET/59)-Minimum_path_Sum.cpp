#include<bits/stdc++.h>
int helper(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &dp)
{
    if(x==grid.size()-1 && y==grid[0].size()-1)
    {
        return grid[x][y];
    }
    if(x>=grid.size() || y>= grid[0].size()) return INT_MAX;
    
    if(dp[x][y]!=-1) return dp[x][y];
    
    int right= helper(x,y+1,grid,dp);
        int down= helper(x+1,y,grid,dp);
    
   return dp[x][y]=grid[x][y]+min(right,down);
    
    
    
    
}
int minSumPath(vector<vector<int>> &grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    return helper(0,0,grid,dp);
    
}