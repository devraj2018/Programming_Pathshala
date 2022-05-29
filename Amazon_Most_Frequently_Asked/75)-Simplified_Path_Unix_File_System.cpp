class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string>s;
        int n=path.length();
        int i=0;
        
        while(i<n)
        {
              string temp="";
              while(i<n && path[i]!='/')
              {
                   temp+=path[i];
                   i++;
            }
            
            if(temp.size()==0){i++; continue;}
            else if(temp==".") continue;
            else if(temp=="..")
            {
                 if(!s.empty()) s.pop();
            }
            else{
                s.push(temp);
            }
            
        }
        
        string ans="";
        while(!s.empty())
        {
             ans= "/"+s.top()+ans;
            s.pop();
        }
        if(ans.size()==0) ans+="/";
        return ans;
        
        
    }
};