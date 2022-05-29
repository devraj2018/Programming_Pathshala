------------------------------------------------------------------------------------------------------------------------
------------------------------    O(N) Time and O(1)   Space   ----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n=s.length();
        int curr_count=0;
        for(int i=0;i<n;i++)   //. Mark for Extra close bracket
        {
             if(s[i]>='a' && s[i]<='z') continue;
             if(s[i]=='(') curr_count++; 
             else
                 {
                   curr_count--;
                   if(curr_count<0)
                     {
                      curr_count=0;
                      s[i]='#';
                     }
                }


            
            
        }
        // Reverse of Above Step for Extra Open Bracket
         curr_count=0;
         for(int i=n-1;i>=0;i--)
        {
             if(s[i]>='a' && s[i]<='z') continue;
             if(s[i]==')') curr_count++; 
             else
                {
                  curr_count--;
                  if(curr_count<0)
                     {
                      curr_count=0;
                      s[i]='#';
                     }
                }
        }
        
        
        
        
         string ans="";
        for(int i=0;i<s.length();i++) if(s[i]!='#') ans+=s[i];
        return ans;    
        
        
        
        
    }
};
------------------------------------------------------------------------------------------------------------------------
------------------------------    O(N) Time and O(N)   Space   ----------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------
 

 
class Solution {
public:
    string minRemoveToMakeValid(string s) {
         stack<int>stk;  // Index of invalid character parenenthese
         for(int i=0;i<s.length();i++)
           {
              if(s[i]>='a' && s[i]<='z') continue;
              if(s[i]=='(') stk.push(i);
              else
                {
                  if(stk.empty()) s[i]='#';             // Then this closing bracket is invalid
                  else stk.pop();   
                }
           }
        
        while(!stk.empty())  // For remainig open bracket which dont have closing bracket
        {
            s[stk.top()]='#';
            stk.pop();
        }
        
        string ans="";
        for(int i=0;i<s.length();i++) if(s[i]!='#') ans+=s[i];
        return ans;
        
    }
};
 