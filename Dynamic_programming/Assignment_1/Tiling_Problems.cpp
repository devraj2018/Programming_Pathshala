class Solution {
  public:
    long long numberOfWays(long long n) {
        if(n==1|| n==2) return n;
        long long mod=1e9+7;
        long long a=1,b=2;
        long long c;
        for(int i=3;i<=n;i++)
           {
           c=(a%mod+b%mod)%mod;
           a=b;b=c;
          }
       return c;
    }
};