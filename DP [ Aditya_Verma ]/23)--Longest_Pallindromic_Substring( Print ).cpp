class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int maxx=0;
        int i=0,n=s.length();
        while(i<n)
        {
             int left=i,right=i;
             char curr=s[i];
            while(i<n && s[i]==curr)
             {
                i++;
             }
            right=i-1;
            
            while(left>=0 && right<n && s[left]==s[right])
            {
                left--;right++;
            }
            
            if(right-left-1 >maxx)
            {
                maxx=right-left-1;
                ans=s.substr(left+1,maxx);
            }
            
            
            
        }
        return ans;
    }
};