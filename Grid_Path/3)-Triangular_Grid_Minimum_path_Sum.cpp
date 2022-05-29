class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        vector<int>dp(n,0);
        
        if(n==1) return triangle[0][0];
        dp[0]=triangle[0][0];
        for(int i=1;i<n;i++)
        {
            vector<int>curr(i+1,0);
            
             for(int j=0;j<=i;j++)
             {
                 if(j==0)
                     curr[j]=dp[0]+triangle[i][j];
                 else if(j==i)
                     curr[j]=dp[j-1]+triangle[i][j];
                 else
                     curr[j]=min(dp[j],dp[j-1])+triangle[i][j];
                 
             }
             
            
            dp=curr;
       }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans,dp[i]);
        
        return ans;
        
    }
};