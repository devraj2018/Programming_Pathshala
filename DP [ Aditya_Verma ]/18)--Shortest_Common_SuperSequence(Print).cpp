class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
          for(int i=1;i<=n;i++)
           {                                          //   LCS Part
             for(int j=1;j<=m;j++)
                {
                 if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                 else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
           }
        string scs="";
        int i=n,j=m;
        while(i>0 && j>0)
        {
             if(str1[i-1]==str2[j-1])
             {
                 scs.push_back(str1[i-1]);
                 i--;j--;
             }
             else if(dp[i-1][j]>dp[i][j-1])
             {
                 scs.push_back(str1[i-1]);             // If we are skipping ith row then include that char
                 i--;                                  // from 1st string
             }
            else{
                 scs.push_back(str2[j-1]);  // Store curr and move to max side
                 j--;          // If we are skipping jth col then include that char from 2nd str
              }
       }
        
        while(i>0)           // Include all remaining part of first
        {
             scs.push_back(str1[i-1]);
              i--;
        }
        while(j>0)       // Include all remaining part of second
        {
             scs.push_back(str2[j-1]);
              j--;
        }
        reverse(scs.begin(),scs.end());   // Then reverse because we store from backward direction
        
        return scs;
    }
};

-------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------


// --------   Mehod -2  Little bit lengthy -----//
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n=str1.length();
        int m=str2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                 if(str1[i-1]==str2[j-1])
                     dp[i][j]=1+dp[i-1][j-1];
                 else
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        string lcs="";
        int i=n,j=m;
        while(i>0 && j>0)
        {
             if(str1[i-1]==str2[j-1])
             {
                 lcs.push_back(str1[i-1]);
                 i--;j--;
             }
             else if(dp[i-1][j]>dp[i][j-1]) i--;
             else j--;
             
            
        }
        reverse(lcs.begin(),lcs.end());
        i=0,j=0;int k=0;
        int lcs_length=lcs.length();
        string scs="";
         while( k<lcs_length)
          {
             if(str1[i]==lcs[k] && str2[j]==lcs[k])
                {
                  scs+=str1[i];
                  i++;j++;k++;
                }
              else if(str1[i]==lcs[k])  // Means str2 ele is extra so add that
                {
                   scs+=str2[j];
                   j++;
                }
              else if(str2[j]==lcs[k])   // Means str1 ele is extra so add that
               { scs+=str1[i];
                 i++;
                }
              else
                {
                  scs+=str2[j];   // Means both str1 and str2 ele is extra so add both
                   j++;
                  scs+=str1[i];
                   i++;
                }
          }
        while(i<n) scs+=str1[i++];
        while(j<m) scs+=str2[j++];
        
        return scs;

        
        
    }
};