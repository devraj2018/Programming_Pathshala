class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        long num1=LONG_MIN;
        long num2=LONG_MIN;
        long num3=LONG_MIN;
        
        for(auto x:nums)
        {
             if(x==num1 || x==num2 || x==num3) continue;
             if(x>num1)
             {
                 num3=num2;
                 num2=num1;
                 num1=x;
                 
             }
            else if(x>num2)
            {
                 num3=num2;
                 num2=x;
            }
            else if(x>num3)
            {
                num3=x;
            }
            
      }
        if(num3==LONG_MIN || num2==LONG_MIN) return num1;
        return num3;
        
        
    }
};