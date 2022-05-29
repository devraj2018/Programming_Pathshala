class Solution {
public:
    string dict[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void helper(string &digits,int curr_I,string curr_path,vector<string>&res)
    {
         if(curr_I==digits.length())
         {
             res.push_back(curr_path);
             return;
         }
        
          for(int i=0;i<dict[digits[curr_I]-'0'].length();i++)
           {
             helper(digits,curr_I+1,curr_path+dict[digits[curr_I]-'0'][i],res);
            
           }
      
    }
    vector<string> letterCombinations(string digits) {
        
         if(digits.length()==0) return {};
         vector<string>res;
         helper(digits,0,"",res);
          return res;
        
        
    }
};