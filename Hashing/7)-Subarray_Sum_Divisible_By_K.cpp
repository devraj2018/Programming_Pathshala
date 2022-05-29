/*
Then, if Si%k=rem1 and Sj%k=rem2
if both sums leave same remainder,
Si%k=Sj%k => (Sj%k-Si%k)Si%k=0
That means subarray sum from (i+1) to j will be divisible by k;
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int curr_sum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+= nums[i];
            int rem=curr_sum%k;
            
            if(rem<0)   //Important edge case
                rem+=k;    
           
            if(mp.find(rem)!=mp.end())
            {
                ans+= mp[rem];
            }
            
            
          mp[rem]++;
          
         }
        return ans;
        
    }
};