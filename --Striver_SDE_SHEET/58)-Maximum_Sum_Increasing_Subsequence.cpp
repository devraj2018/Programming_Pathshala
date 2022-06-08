int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	 vector<int>dp=rack;
     int maxx=dp[0];
     for(int i=1;i<n;i++)
     {
         for(int j=i-1;j>=0;j--)
         {
             if(rack[j]<rack[i])
               dp[i]=max(dp[i],dp[j]+rack[i]);
             
         }
         maxx=max(maxx,dp[i]);
    }
    return maxx;
}