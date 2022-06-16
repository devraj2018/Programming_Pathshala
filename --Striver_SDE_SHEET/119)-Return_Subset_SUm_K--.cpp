void helper(vector<int> &arr,int n,int i,int k, vector<int> &v,vector<vector<int>>&ans){

   

   if(k==0){

       ans.push_back(v);

   }

   if(i>=n) return ;

   for(;i<n;i++){

       v.push_back(arr[i]);

     helper(arr,n,i+1,k-arr[i],v,ans);

     v.pop_back();

   }

}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>>res;
    vector<int>curr;
    
     helper(arr,n,0,k,curr,res);
    return res;
    
}