// O(n) Time and O(n)Space -->>   Tabulation
int frogJump(int n, vector<int> &heights)
{
    if(n==1) return 0;
    if(n==2) return abs(heights[1]-heights[0]);
    
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=abs(heights[1]-heights[0]);
    for(int i=2;i<n;i++)
    {
        dp[i]=min( dp[i-1]+abs(heights[i]-heights[i-1]),dp[i-2]+abs(heights[i]-heights[i-2]));
    }
    return dp[n-1];
}

// O(n) Time and O(1) Space -->>   Space Optimized Dp
int frogJump(int n, vector<int> &heights)
{
    if(n==1) return 0;
    if(n==2) return abs(heights[1]-heights[0]);
    
    
    int a=0;
    int b=abs(heights[1]-heights[0]);
    int c;
     for(int i=2;i<n;i++)
    {
        c=min(a+abs(heights[i]-heights[i-2]),b+abs(heights[i]-heights[i-1]));
        a=b;
        b=c;
        
    }
    return c;
}