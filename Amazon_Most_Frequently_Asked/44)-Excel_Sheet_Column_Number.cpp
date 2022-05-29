class Solution {
public:
    int titleToNumber(string s) {
        
        long long pow=1;
        long long ans=0;
        for(int j=s.length()-1;j>=0;j--)
        {
             long long n= (s[j]-'A')+1;
            
             ans+= n*pow;
             pow*=26;
           
        }
        return (int)ans;
    }
};