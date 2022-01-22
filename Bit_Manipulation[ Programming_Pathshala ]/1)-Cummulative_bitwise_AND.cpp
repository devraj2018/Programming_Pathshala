class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans=0;
        long long power_2=1;  // To avoid overflow Condition 
        int length=right-left;
        int dist_from_right;
        for(int i=0;i<32;i++)
        {
            if(power_2>=length)
            {
                if( (left &(1<<i))==0 ||  (right &(1<<i))==0)
                    continue;
                ans|=(1<<i);
            }
            power_2<<=1;  // If we use int here it get overflow bcz when i=31 it gets overflow
                
         
        }
        return ans;
        
    }
};

// In this method we start from MSB//

class Solution {
public:
      int rangeBitwiseAnd(int left, int right)
      {  int ans=0;
          long res= (1L<<31);
         
          while(res)
          {
               if((left& res)  == (right&res))
               {
                  if(left&res) ans|=res;
                  res>>=1;
               }
               else 
                   break;
             
          }
         return ans;
     }
};