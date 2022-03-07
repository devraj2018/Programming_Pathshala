class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        int maxx=0;
        
        while(mp.size()!=0)
        {
             auto x=mp.begin();
            
             int curr=x->first;
             mp.erase(x);
            
             int left=curr-1,right=curr+1;
            
             while(mp.find(left)!=mp.end()){
                 mp.erase(left);
                 left--;
             }
             while(mp.find(right)!=mp.end()){
                 mp.erase(right);
                 right++;
             }
            
            maxx=max(maxx,right-left-1);
            
        }
        return maxx;
        
       
    }
};
