//  ---------------   Top Down- DP-------------------//
class Solution{
  public:
  vector<int>dp;
  int helper(int price[],int length)
  { 
       if(length<=0) return 0;
       int maxx=INT_MIN;
       if(dp[length]!=-1) return dp[length];
       
       for(int l=1;l<=length;l++)
       {  maxx=max(maxx,price[l-1]+helper(price,length-l));
       }
       return dp[length]=maxx;
     }
    int cutRod(int price[], int n) {
        dp.resize(n+1,-1);
        return helper(price,n);
    }
};
//  ---------------   Bottome-Up- DP-------------------//
class Solution{
  public:
     int cutRod(int price[], int n) {
         vector<int>dp;
         dp.resize(n+1,0);
         
        for(int i=1;i<=n;i++)
           { int maxx=INT_MIN;
               for(int j=1;j<=i;j++)
                  {   maxx=max(maxx,price[j-1]+dp[i-j]);
                  }
                dp[i]=maxx;
            }
         return dp[n];
     }
};