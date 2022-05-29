class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char>s;
        
        int i=0;
        while(i<n)
        {
            
              while(k && !s.empty() && s.top()>num[i])
              {
                   s.pop();
                   k--;
                }
             s.push(num[i]);
             i++;      
        }
        
         while(k && !s.empty())
        {
             
            s.pop();
             k--;
        } 
        string res="";
        while(!s.empty())
        {
            res+=s.top();
            s.pop();
        }
         
        while(res.size()>0 && res[res.size()-1]=='0') res.pop_back();
        reverse(res.begin(),res.end());
       
        if(res.size()==0) return "0";
        return res;
        
        
    }
};