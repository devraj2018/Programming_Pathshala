class Solution {
public:
    string dict[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>res;
    
    void helper(string digits,int curr_I,string curr_str)
    {
         if(curr_I==digits.length())
           {
             res.push_back(curr_str);
             return;
           }
          string temp=dict[digits[curr_I]-'0'];
          for(int j=0;j<temp.length();j++)  helper(digits,curr_I+1,curr_str+temp[j]);
     }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        helper(digits,0,"");
        return res;
     }
};