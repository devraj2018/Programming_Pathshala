-----------------------------------------------------------------------------------
// --------   Check Thoda sa TLE aa rha hai last k test cases mai dfs se----//
------------------------------------------------------------------------------------
class Solution
{
	public:
	     unordered_map<string,int>mp;
	     vector<vector<int>>dp;
	     void dfs(int i,int j,string curr_str,string a,string b)
	       {
	            if(i==0 || j==0)
	                {
	                  mp[curr_str]++;
	                  return;
	               }
	             
	            if(a[i-1]==b[j-1]) dfs(i-1,j-1,curr_str+a[i-1],a,b);
                else if(dp[i-1][j]>dp[i][j-1]) dfs(i-1,j,curr_str,a,b);
                else if(dp[i-1][j]<dp[i][j-1]) dfs(i,j-1,curr_str,a,b);
                else
                  {
                      dfs(i-1,j,curr_str,a,b);
                      dfs(i,j-1,curr_str,a,b);
                  }
	      }
		vector<string> all_longest_common_subsequences(string a, string b)
		{
		    int n1=a.length();
            int n2=b.length();
            dp.resize(n1+1,vector<int>(n2+1,0));
  
            for(int i=1;i<=n1;i++)
                {
                     for(int j=1;j<=n2;j++)
                         {
                             if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                             else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                         }
                }
  
            dfs(n1,n2,"",a,b);
            
            vector<string>final;
           
             for(auto s:mp) {   // unordered-map to avoid duplicate subsequence
               string temp=s.first;
               reverse(temp.begin(),temp.end());  // because in dfs we start from last,so to correct that
               final.push_back(temp);
               
           }
           sort(final.begin(),final.end());  // for lexographic order
           return final;

		}
};