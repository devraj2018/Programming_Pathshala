class Solution{
  public:
    int longestKSubstr(string s, int k) {
     
       int n=s.length();
       unordered_map<char,int>mp;
       int left=0;
        
       int maxx=-1;
       for(int right=0;right<n;right++)
          {
             mp[s[right]]++;
             while(mp.size()>k)
                {
                   mp[s[left]]--;
                   if(mp[s[left]]==0) mp.erase(s[left]);
                   left++;
                }
             if(mp.size()==k)
             maxx=max(maxx,right-left+1);
          }
       return maxx;
       
    }
};