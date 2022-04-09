class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int curr_sum=0,res=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        
        for(int i=0;i<n;i++)
        {
             curr_sum+=nums[i];
             int rem= (curr_sum%k +k)%k;
            
             if(mp.find(rem)!=mp.end())
                 res+=mp[rem];
            
            mp[rem]++;
            
            
        }
        return res;
        
    }
};