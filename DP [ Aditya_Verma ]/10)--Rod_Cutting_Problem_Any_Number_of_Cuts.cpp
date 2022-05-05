class Solution{ // Ditto Unbounded Knapsack
  public:
    int cutRod(int price[], int n) {
       
      // W==> n
      //val[]==> price[]
      //wt[]==> length[]-> We need to create length arr of size n => [1,2,3,4,4........n]This is lenght array

      // we check wt[i-1]<=j -->> for example for j==1 && i==1 wt[0]<=1 ==> and our wt[0]=1,wt[1]=2
      // So we can directly check    i<=j  Without creating length Array
      
      class Solution{
  public:
    int cutRod(int price[], int n) {
       
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                 if(j>=i) dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
                 else dp[i][j]=dp[i-1][j];
                
            }
        }
        return dp[n][n];
       
    }
};
};