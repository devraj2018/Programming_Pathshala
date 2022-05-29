class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>>stk;
        if(k==1) return "";
        
        for(int i=0;i<s.length();i++)
        {
            if(stk.empty()) stk.push({s[i],1});
            else
            {
                if(stk.top().first==s[i]) stk.push({s[i],stk.top().second+1});
                else stk.push({s[i],1});
                
                
                if(stk.top().second==k)
                {
                    int x=k;
                    while(x--) stk.pop();
                }
                

            }
            
                    
        }
        string ans="";
        while(!stk.empty())
        {
            ans+= stk.top().first;
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};