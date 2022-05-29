//    -----------  Same for String     -----//
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        int maxx=0;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                 if(nums1[i-1]==nums2[j-1]) dp[i][j]= 1+dp[i-1][j-1];
                 else dp[i][j]=0;
                
                 maxx=max(maxx,dp[i][j]);
                
            }
        }
        return maxx;
        
        
    }
};

// ===========Memoization ===========//

class Solution {
public:
    int maxx=0;
    
    int helper(vector<int>& nums1,int n1, vector<int>& nums2,int n2, vector<vector<int>>&dp)
    {
        if(n1==0 || n2==0) return  dp[n1][n2]=0;
        
        int ans=0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        
        if(nums1[n1-1]==nums2[n2-1]) ans= 1+helper(nums1,n1-1,nums2,n2-1,dp);
        
        helper(nums1,n1,nums2,n2-1,dp);
        helper(nums1,n1-1,nums2,n2,dp);
        
        maxx=max(maxx,ans);
        return dp[n1][n2]= ans;
        
         
    }
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        helper(nums1,n1,nums2,n2,dp);
        return maxx;
        
    }
};