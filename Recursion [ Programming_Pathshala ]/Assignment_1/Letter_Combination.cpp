class Solution {
public:
    string dict[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void helper(string &digits, int digits_index,vector<string>&res,string curr)
    {
        if(digits_index>= digits.length())
            { res.push_back(curr);
              return;
            }
        
         string current=dict[digits[digits_index]-'0'];
        
         for(int i=0;i<current.length();i++)
         {    curr.push_back(current[i]);
              helper(digits,digits_index+1,res,curr);
              curr.pop_back();
         }
       
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return {};
        vector<string> res;
        string curr="";
        helper(digits,0,res,curr);
       
        return res;
        
        
    }
};