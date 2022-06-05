class Solution {
public:
    string dict[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>res;
    void helper(string &digits,string &curr,int curr_I)
    {
         if(curr_I==digits.length())
         {
             res.push_back(curr);
             return;
         }
        
         
        for(int i=0;i<dict[digits[curr_I]-'0'].length();i++)
        {
             curr+= dict[digits[curr_I]-'0'][i];
             helper(digits,curr,curr_I+1);
             curr.pop_back();
        }
        
       
    }
    
    vector<string> letterCombinations(string digits) {
       
        string curr="";
        int curr_I=0;
        if(digits.size()==0) return res;
        
        helper(digits,curr,curr_I);
        return res;
        
    }
};