class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>>stk;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
             if(stk.empty()) stk.push({s[i],1});
             else{
                 
                 if(s[i]==stk.top().first){
                     stk.push({s[i],stk.top().second+1});
                 }

                 
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