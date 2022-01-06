class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxx=0;
        int curr_sum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++)
           {   curr_sum+= (nums[i]==1)?1:-1;
            
               if(mp.find(curr_sum)!=mp.end()) maxx=max(maxx,i-mp[curr_sum]);
               else mp[curr_sum]=i;
           }
        return maxx;
        
    }
};