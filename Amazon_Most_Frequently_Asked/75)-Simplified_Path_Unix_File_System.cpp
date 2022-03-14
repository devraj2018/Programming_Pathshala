class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        stack<string>stk;
        
        int i=0;
        string temp="";
        while(i<n)
        {    
             temp="";
             while(i<n && path[i]!='/')
             {
                 temp+=path[i];
                 i++;
             }
            
            if(temp==""){i++; continue;}
            if(temp==".") continue;
            if(temp==".."){
                if(!stk.empty()) stk.pop();
            }
            else
                stk.push(temp);
       }
        string ans="";
        while(!stk.empty())
        {
            ans = "/"+ stk.top() + ans;
            stk.pop();
        }
        if(ans=="") ans+="/";
        return ans;
        
    }
};