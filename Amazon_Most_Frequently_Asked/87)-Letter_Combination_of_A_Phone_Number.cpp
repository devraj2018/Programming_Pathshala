class Solution {
public:
    vector<string>res;
    string dict[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void helper(string &digits,int curr_I,string curr_str)
       {
           if(curr_I==digits.length())
             {
               res.push_back(curr_str);
               return;
             }
        
            for(int i=0;i<dict[digits[curr_I]-'0'].length();i++)
               {
                     helper(digits,curr_I+1,curr_str+dict[digits[curr_I]-'0'][i]);
               }
      
        
    }
    vector<string> letterCombinations(string digits) {
          if(digits.length()==0) return res;
          helper(digits,0,"");
          return res;
        
    }
};