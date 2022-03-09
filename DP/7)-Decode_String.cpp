class Solution {
public:
    vector<int> arr;
     int helper(string s,int curr_I)
     {     if(curr_I==s.length()) return 1;
          
           if(curr_I>s.length()) return 0;
          
            if(s[curr_I]=='0') return 0;
         
            if(arr[curr_I]!=-1) return arr[curr_I];
            int one=0,two=0;
          
            if(( s[curr_I]>='3' )|| (curr_I+1<s.length() && s[curr_I]=='2' && s[curr_I+1]>='7'))
                one=helper(s,curr_I+1);
            else
              {    
              one=helper(s,curr_I+1);
              two=helper(s,curr_I+2);
              }
             return arr[curr_I]=one+two;
       }
    
    
    int numDecodings(string s) {
         int curr_I=0;
        arr.resize(s.length(),-1);
        return helper(s,curr_I);
        
    }
};