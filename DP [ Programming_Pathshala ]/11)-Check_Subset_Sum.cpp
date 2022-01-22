//---------------Tabulation----------------//
class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
         vector< vector<bool>>dp(N+1, vector<bool>(sum+1,false));
         
         for(int i=0;i<=N;i++)
           dp[i][0]=true;
           
         for(int i=1;i<=N;i++)
         {
              for(int j=1;j<=sum;j++)
                {
                  dp[i][j]=dp[i-1][j];
                  
                  if(j-arr[i-1]>=0) dp[i][j] =dp[i][j] | dp[i-1][j-arr[i-1]];
               }
          }
         return dp[N][sum];
     }
};


//---------------Memoization-----------------//
class Solution{   
public:
    bool ans=false;
    vector< vector<int>>dp;
     int helper(int arr[],int &n,int sum,int curr_I=0)
      { 
        if(ans) return 1;
        if(sum==0) {
            ans=true;
            return 1;
         }
        if(curr_I==n || sum<0) return 0;
        
        if(dp[curr_I][sum]!=-1) return dp[curr_I][sum];
        
        int taken=helper(arr,n,sum-arr[curr_I],curr_I+1);
        int not_taken=helper(arr,n,sum,curr_I+1);
        
        if(taken ==1 || not_taken==1) return dp[curr_I][sum]=1;
        else return dp[curr_I][sum]=0;
       
    }
    bool isSubsetSum(int N, int arr[], int sum){
         dp.resize(N+1, vector<int>(sum+1,-1));
         helper(arr,N,sum);
         return ans;
    }
};