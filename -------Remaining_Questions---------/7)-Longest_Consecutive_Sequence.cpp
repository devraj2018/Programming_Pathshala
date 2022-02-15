class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        if(n==0) return 0;
        
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int maxx=1;
        while(mp.size()>1)
        {
               int x= (mp.begin()->first);
               int y=x;
               mp.erase(mp.begin());
               int lft=0,rgt=0;
               while( mp.find(x-1)!=mp.end())
               {
                   lft++;
                   x--;
               }
              while( mp.find(y+1)!=mp.end())
               {
                   rgt++;
                   y++;
               }
             
             maxx=max(maxx,lft+rgt+1);
     }
        return maxx;
        
    }
};