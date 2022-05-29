class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(auto x:nums) mp[x]++;
        int ans=0;
       for(auto x:mp)
        {
             if(x.second==-1) continue;
           
             int num=x.first;
             int count=1;
             int left=num-1;
             int right=num+1;
             while(mp.find(left)!=mp.end() && mp[left]!=-1)
             {
                 count++;
                 mp[left]=-1;
                 left--;
             }
           while(mp.find(right)!=mp.end() && mp[right]!=-1)
             {
                 count++;
                 mp[right]=-1;
                 right++;
             }
           ans=max(ans,count);
             
       }
        return ans;
        
        
    }
};