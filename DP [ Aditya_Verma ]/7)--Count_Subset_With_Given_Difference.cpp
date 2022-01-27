// Let sum of subset 1 be s1 and subset 2 with s2
// s1 - s2 = diff (given)
// s1 + s2=sum of array (logical)
// Therefore adding both eq we get :
// 2s1= diff + sum of array
// s1= (diff + sum of array)/2;
// Problem reduces to find no of subsets with given sum s1
int count_zero_till_that_index(int arr[],int i)
{
    int count=0;
    for(int j=0;j<i;j++)
    {
        if(arr[j]==0) count++;
    }
    return count;
}
int CountSubsetSum(int arr[],int n,int sum)
{
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0)); // First row automatically initalized by zero

    for(int i=0;i<=n;i++) // for first colum intialized all with one but if we have 0 or more zeros,Thn initialization
    {                    // ---  is different
       dp[i][0]= pow(2,count_zero_till_that_index(arr,i));
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
              if(arr[i-1]<=j)
               dp[i][j]= dp[i-1][j-arr[i-1]] + dp[i-1][j];
             else
               dp[i][j]=dp[i-1][j];

        }
    }

    return dp[n][sum]; 
 
}
int count(int arr[],int n,int diff)
{
    int total_sum=0;
    for(int i=0;i<n;i++) total_sum+= arr[i];

    if(total_sum<abs(diff) || (total_sum+diff)%2==1) return 0;  // Iss case mai answer zero hi hoga

    int sum_subset_1= (diff + total_sum)/2;

    return CountSubsetSum(arr,n,sum_subset_1);


}



