class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int k) 
    { 
         
        unordered_map<int,int>mp;
        mp[0]=-1;
        int curr_sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
             curr_sum+=nums[i];
             if(mp.find(curr_sum-k)!=mp.end())
                 ans=max(ans,i-mp[curr_sum-k]);
             
             if(mp.find(curr_sum)==mp.end())
                  mp[curr_sum]=i;
            
            
        }
        return ans;
    } 

};
