class Solution {
public:
    string removeDuplicates(string s) {
        
        int n=s.length();
        int i=0;
        stack<pair<char,int>>stk;
        
        for(i=0;i<n;i++)
        {
             if(stk.empty()) stk.push({s[i],1});
             else if(stk.top().second==2)
                {
                     int x=stk.top().second;
                     while(x--) stk.pop();
                 
                    if(stk.empty()) stk.push({s[i],1});
                    else if(stk.top().first==s[i]) stk.push({s[i],stk.top().second+1});
                    else stk.push({s[i],1});
                }
             else if(stk.top().first==s[i]) stk.push({s[i],stk.top().second+1});
             else stk.push({s[i],1});
              
          
         }
         if(!stk.empty() && stk.top().second==2)
         {
                   int x=stk.top().second;
                     while(x--) stk.pop();
         }
             
        string res="";
        while(!stk.empty())
        {
            res+=stk.top().first;
            stk.pop();
        }
         reverse(res.begin(),res.end());
        return res;
    }
};