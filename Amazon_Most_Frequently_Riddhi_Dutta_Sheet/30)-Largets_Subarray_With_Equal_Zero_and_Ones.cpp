class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int ans=0;
        int curr_sum=0;
        for(int i=0;i<N;i++)
        {
            if(arr[i]==0) curr_sum-=1;
            else curr_sum+=1;
            
            if(mp.find(curr_sum)!=mp.end())
               ans=max(ans, i-mp[curr_sum]);
            else mp[curr_sum]=i;
        }
        return ans;
    }
};