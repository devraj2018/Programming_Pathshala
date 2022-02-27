class Solution {
public:
    string longestPalindrome(string s) {
        
        
        int n=s.length();
        if(n<=1) return s;
        int maxx=0;
        int starti,endi;
        
        for(int i=0;i<n;i++)
        {
             int li=i,ri=i;
             while(ri<n-1 && s[ri]==s[ri+1]) ri++;  // for Duplicate element
              
             i=ri;
             
             while(li>0 &&  ri<n-1 && s[li-1]==s[ri+1]) // Both side expanding pallindrome
             {   li--;
                 ri++;
             }
           
             
            if(maxx< ri-li+1)
            {   maxx= ri-li+1;
                starti=li;
                endi=ri;
             }
            
         }
      //  cout<<starti<<" "<<endi<<" "<<maxx<<endl;
        string temp= s.substr(starti,endi-starti+1);
        return temp;
        
        
    }
};