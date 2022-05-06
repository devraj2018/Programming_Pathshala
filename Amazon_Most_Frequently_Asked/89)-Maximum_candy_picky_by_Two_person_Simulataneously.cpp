int ans=INT_MIN;
int helper(int r, int c, vector<vector<int>> &grid,vector<vector<vector<int>>>&dp,int i,int j1,int j2)
{
	
	    if(i==r-1)
	    	{
			   if(j1==j2) return grid[i][j1];
			   else return grid[i][j1]+grid[i][j2];
		    }
	
	   
	    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
	    int ans=INT_MIN;
	    for(int first=-1;first<=1;first++)
	      {
		   for(int second=-1;second<=1;second++)
		     {
			  
			   int new_j1=j1+first; 
			   int new_j2=j2+second;
			   if(new_j1<0 || new_j2<0 || new_j1>=c || new_j2>=c) continue;
			   
			   if(j1==j2)  ans=max(ans,grid[i][j1]+helper(r,c,grid,dp,i+1,new_j1,new_j2));
			   else  ans=max(ans,grid[i][j1]+grid[i][j2]+helper(r,c,grid,dp,i+1,new_j1,new_j2));
		     }
	      }
	
	   return dp[i][j1][j2]=ans;
	 	
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
   
	vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return helper(r,c,grid,dp,0,0,c-1);
	 
}