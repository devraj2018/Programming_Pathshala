class Solution{
public:	//Hello
	int longSubarrWthSumDivByK(int nums[], int n, int k)
	{
	    int ans=0;
        unordered_map<int,int>mp;
        int currsum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        { 

            
            currsum+=nums[i];
            
            int rem= (k+currsum%k)%k;
            
            if(mp.find(rem)!=mp.end())
            {
                ans=max(ans,i-mp[rem]);
            }
            else
               mp[rem]=i;



              
        }
        return ans;
	}
};