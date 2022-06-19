 
int dp[102][102];

  
int calculateCost(vector<int> &arr, int i, int j)
{
    
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int ans = INT_MAX;

     for(int k = i; k < j; k++)
      { 
          int temp = calculateCost(arr, i, k) + calculateCost(arr, k + 1, j) + (arr[k] * arr[i - 1] * arr[j]);
          ans = min(ans, temp);
      }
    return  dp[i][j] = ans;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    
   
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            dp[i][j] = -1;
        }
    }

   
    return calculateCost(arr, 1, N - 1);
 
    
}