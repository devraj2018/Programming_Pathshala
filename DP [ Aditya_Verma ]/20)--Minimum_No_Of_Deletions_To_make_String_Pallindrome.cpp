#include <bits/stdc++.h>
using namespace std;

int minDeletions(string X, int n) { 
   
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
        string Y= X;
        reverse(Y.begin(),Y.end());
        
        for(int i=1;i<=n;i++)
          {
            for(int j=1;j<=n;j++)
              {
                 
                 if(X[i-1]==Y[j-1])
                     dp[i][j]=1+dp[i-1][j-1];
                 else
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 
             }
         }
        return n-dp[n][n];
    
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
} 


