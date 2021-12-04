// for 10 --10 is made up of 5*2
// So we need to count number of factor of 2 and 5
// Factor of 5 is always less in number in comparison to 2
// So trailing zero== number of factor of 5


class Solution {
public:
    int trailingZeroes(int n) {
        
        int ans=0;
        int power_of_5=5;
        while(power_of_5<=n)
        {                      
            ans+= n/power_of_5;
            power_of_5*=5;
        }
        return ans;
        
    }
};