Index : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
num : 0 1 1 2 1 2 2 3 1 2 2 3 2 3 3 4
Do you find the pattern?
Obviously, this is overlap sub problem, and we can come up the DP solution. For now, we need find the function to implement DP.
dp[0] = 0;
dp[1] = dp[0] + 1;
dp[2] = dp[0] + 1;
dp[3] = dp[1] +1;
dp[4] = dp[0] + 1;
dp[5] = dp[1] + 1;
dp[6] = dp[2] + 1;
dp[7] = dp[3] + 1;
dp[8] = dp[0] + 1;
...

This is the function we get, now we need find the other pattern for the function to get the general function. After we analyze the above function, we can get

*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i&(i-1)]+1;
        }
        return dp;
        
        
    }
};

//      --------------- nlogn -------------------//
/*
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i=0;i<=n;i++)
        {
             int count=0;
             int j=i;
             while(j>0)
             {
                 count+= (j&1);
                 j/=2;
             }
            res.push_back(count);
            
            
        }
        return res;
        
    }
};
*/