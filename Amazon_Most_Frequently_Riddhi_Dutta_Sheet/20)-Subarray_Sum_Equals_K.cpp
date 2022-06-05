class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        
        int curr_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            
            if(mp.find(curr_sum-k)!=mp.end())
                ans+= mp[curr_sum-k];
            mp[curr_sum]++;
        }
        return ans;
        
    }
};