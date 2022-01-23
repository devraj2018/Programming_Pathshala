
//Divide it into two Subset such that Difference of Subset sum is minimum
//{. + .+ . } - {. + .+ . }  Any subset contain any no. of item or zero ==> no of item in S1 +  no of item in S2 = total item in array
//If one item is in S1 then It should not be in S2 and Vice Versa
//Set1->Have sum as S1 and Set2->Have sum as S2, we need to find min(abs(S1 - S2))

//If one sum is S1 then S2 is (total-S1)     Considering s2-s1 because i always choose s2>=s1 =>So by default its absolute
//So => min(s2-s1) => min(total- s1 -s1) => min(total -2*s1)

//We call Subset sum and make dp table and we pass sum as total sum 
//So that last row of our dp table have info,That we can make any subset having that sum

//Range of s1 and s2 is  [0 .....................total] and its our last row of DP
//So for i=0 to sum/2 in last row wherever we find true that means with n size array we can make subset with sum i;


//Then at last for(int i=0 to i<candidate.size) we can find ans=min(ans, total- 2*candidate[i])==>On_All_Candidate_of_S1(min(total - 2*s1))


vector<int> subsetSum(vector<int>&A,int n,int Sum)
{
    vector<vector<int>>dp(n+1,vector<int>(Sum+1));
    vector<int>candidate_for_S1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=Sum;j++)
         {
               if(i==0 && j==0) dp[i][j]=1;
               else if(i==0) dp[i][j]=0;
               else if(j==0) dp[i][j]=1;
               else if(A[i-1]<=j) dp[i][j]= dp[i-1][j-A[i-1]] || dp[i-1][j];
               else dp[i][j]=dp[i-1][j];

         }
    }

    for(int j=0;j<=Sum/2;j++)
    {
        if(dp[n][j]==1) candidate_for_S1.push_back(j);
    }
    return candidate_for_S1;
    


}
int solve(vector<int> &A) {
   int Sum=0;
   for(auto x:A) Sum+=x;

   vector<int> candidate=subsetSum(A,A.size(),Sum);
   int ans=INT_MAX;
   for(int i=0;i<candidate.size();i++)
   {
     ans=min(ans, Sum- 2* candidate[i]);

   }
   return ans;

}