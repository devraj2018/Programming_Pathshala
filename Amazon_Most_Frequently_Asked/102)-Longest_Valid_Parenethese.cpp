class Solution {
public:
    int longestValidParentheses(string s) {
      stack<int>stk;
        int maxx=0;
        stk.push(-1);
       for(int i=0;i<s.length();i++)
       {
            if(s[i]=='(')
                stk.push(i);
            else
            {    stk.pop();
                 if(!stk.empty())
                 {
                     int j=stk.top();
                     maxx=max(maxx,i-j);         
                 }
             else stk.push(i);
              
            }
       }
        return maxx;
        
    }
};

// Brute Force ------  O(n^2)

/*
class Solution {
public:
    int longestValidParentheses(string s) {
        
         int maxx=0;
         for(int i=0;i<s.length();i++)
              {
                 int j=i;
                 int curr_count=0;
                 int prev=-1;
                 while(j< s.length() && curr_count>=0)
                     {
                          if(s[j]=='(') curr_count++;
                          else curr_count--;
                
                          if(curr_count==0) prev=j;
                          j++;
                     }
             
                if(curr_count==0)  maxx=max(maxx,j-i);
                else maxx=max(maxx,prev-i+1);
            
              }
        return maxx;
        
    }
};
*/