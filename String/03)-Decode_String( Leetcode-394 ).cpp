class Solution {
public:
    string helper(string s,int &curr_I)
    {
         if(curr_I== s.length()) return "";
        
         if(s[curr_I]==']') 
         {
             curr_I++;
             return "";
         }
        
         string res="";
        
         int times=0;
         while(curr_I<s.length() && s[curr_I]>='0' && s[curr_I]<='9')
           {
              times= times*10 + (s[curr_I]-'0');
              curr_I++;
           }
        
        string temp="";
        if(times!=0) 
           {  
              curr_I++;
              temp=helper(s,curr_I);
           }
        else if(s[curr_I]>='a' && s[curr_I]<='z')
           {
                  temp.push_back(s[curr_I]);
                  curr_I++;
           }
        res=temp;
        for(int i=1;i<times;i++)
          {
               res+=temp; 
          }
        return res+helper(s,curr_I);
    }
    
    string decodeString(string s) {
        int curr_I=0;
        return helper(s,curr_I);
    }
};