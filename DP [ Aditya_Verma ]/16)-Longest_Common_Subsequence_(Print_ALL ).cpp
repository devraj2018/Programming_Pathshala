-----------------------------------------------------------------------------------
// --------   Check Thoda sa TLE aa rha hai last k test cases mai dfs se----//
------------------------------------------------------------------------------------
class Solution
{
     public:
     void dfs(int m,int n,string X,string Y, vector<vector<int>>&dp,string curr,unordered_map<string,int>&res)
     {
           if(n==0 || m==0)
            {   res[curr]++;
                return;
            }
            
            if(X[m-1]==Y[n-1])  dfs(m-1,n-1,X,Y,dp,curr+X[m-1],res);
            else if(dp[m][n-1]>dp[m-1][n])  dfs(m,n-1,X,Y,dp,curr,res);
            else if(dp[m][n-1]<dp[m-1][n]) dfs(m-1,n,X,Y,dp,curr,res);
            else if(dp[m][n-1] == dp[m-1][n] && X[m-1]!=Y[n-1])
              {   dfs(m,n-1,X,Y,dp,curr,res);
                  dfs(m-1,n,X,Y,dp,curr,res);
              }
             else dfs(m,n-1,X,Y,dp,curr,res);
      }
     
       vector<string> all_longest_common_subsequences(string X, string Y)
		{
		    int m=X.length();
		    int n=Y.length();
		    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
            for(int i=1;i<=m;i++)
                 {  
                     for(int j=1;j<=n;j++)
                         {
                            if(X[i-1]==Y[j-1]) dp[i][j]=1+dp[i-1][j-1];
                            else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                         }
                 }
                
            string curr="";
            unordered_map<string,int>res;
            dfs(m,n,X,Y,dp,curr,res);
            
            vector<string>final_ans;
            for(auto x:res)
            {
                string temp=x.first;
                reverse(temp.begin(),temp.end());
                final_ans.push_back(temp);
            }
            sort(final_ans.begin(),final_ans.end());
            return final_ans;
                
                
                
                
		}
};