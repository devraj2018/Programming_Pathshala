class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        int currsum=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        { 
            currsum+=nums[i];
            
            int rem= (k+(currsum%k))%k;
            
            if(mp.find(rem)!=mp.end())
            {
                ans+=mp[rem];
            }
            mp[rem]++;
            
              
        }
        return ans;
        
    }
};