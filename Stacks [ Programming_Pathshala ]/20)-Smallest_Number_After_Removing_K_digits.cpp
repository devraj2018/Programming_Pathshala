class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        if(n==k) return "0";
        
        stack<char>s;
        for(int i=0;i<n;i++)
        {
             while(k && !s.empty() && s.top()>num[i])
             {
                 s.pop();
                 k--;
             }
            s.push(num[i]);
            if(s.size()==1 && s.top()=='0') s.pop();    // Just to remove Leading Zeros
        }
        while(k && !s.empty())     // If some K left to left
        {                         // Then delete from end because our stack in incresing order 
            k--;                 // From bottom to top
            s.pop();
        }
        string ans="";
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        if(ans.size()==0) return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};