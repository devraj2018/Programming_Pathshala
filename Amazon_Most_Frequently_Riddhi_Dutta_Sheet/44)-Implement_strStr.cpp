class Solution {
public:
    int strStr(string haystack, string needle) {
       
        if(haystack.size()<needle.size()) return -1;
        for(int i=0;i<=haystack.size()-needle.size();i++)
        {
            int j=0;
            
            for(j=0;j<needle.size();j++)
            {
                if(haystack[i+j]!=needle[j]) break;
            }
            if(j==needle.size()) return i;
            
            
        }
        return -1;
    }
};