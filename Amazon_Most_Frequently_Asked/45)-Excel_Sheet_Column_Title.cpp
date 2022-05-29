class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans="";
        
        while(columnNumber)
        {
            columnNumber--;
            
            int rem=columnNumber%26;
            
            ans+= (rem+'A');
            
            columnNumber/=26;
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
    
};