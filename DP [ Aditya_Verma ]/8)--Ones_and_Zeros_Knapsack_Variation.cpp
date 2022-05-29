//  Letcode      474   =========//
class Solution {
public:
    int knapsack(int m,int n,int len, vector<pair<int,int>>&arr,vector<vector<vector<int>>>&dp)
    {
          if(len==0) return 0;
          
          if(dp[len][m][n]!=-1) return dp[len][m][n];
        
          int take=0;
          if(arr[len-1].first<=m && arr[len-1].second<=n)
          {
              take=1+knapsack(m-arr[len-1].first,n-arr[len-1].second,len-1,arr,dp);
          }
          int dont_take=knapsack(m,n,len-1,arr,dp);
          return dp[len][m][n]=max(take,dont_take);
         
       
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>>arr;
        for(int i=0;i<strs.size();i++)
        { 
             int zeros=0,ones=0;
             for(auto &c:strs[i])
             {
                 if(c=='1') ones++;
                 else zeros++;
                 
             }
            arr.push_back({zeros,ones});
           
        }
        int size=strs.size();
        vector<vector<vector<int>>>dp(size+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        
        return knapsack(m,n,size,arr,dp);
        
    }
};