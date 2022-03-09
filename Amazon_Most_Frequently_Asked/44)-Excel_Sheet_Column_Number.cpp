class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        long long ans=0;
        long long curr_power=1;
        int n=columnTitle.length();
        for(int i=n-1;i>=0;i--)
        {
             
            ans+= (columnTitle[i]-'A'+1)*curr_power;
            curr_power*=26;
            
         }
        return (int)ans;
        
    }
};