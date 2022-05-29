class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        if(nums.size()==0) return 0;
        for(auto x:nums)  mp[x]++;
         
        int ans=0;
         while(true)
            {
               auto it=mp.begin();
               int val1=it->first,val2=it->first;
               mp.erase(it); // Don't forget to do this step also
               int left=0,right=0;
               while(mp.find(val1-1)!=mp.end())
                 {
                    left++;
                    mp.erase(val1-1);
                    val1--;
                 }
                 
               while(mp.find(val2+1)!=mp.end())
                 {
                   right++;
                   mp.erase(val2+1);
                   val2++;
                 }
               
               ans=max(ans,left+right+1);
            
               if(mp.begin()==mp.end()) break;
            
         }
        return ans;
    }
};