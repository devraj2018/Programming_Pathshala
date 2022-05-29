class Solution {
public:
    long long numberOfWeeks(vector<int>& nums) {
     
        long long total=0;
          long long maxx=-1;
       
        for(auto x:nums) {
            total+=x;
           
            if(x>maxx)
                maxx=x;
        }
        
          long long remaining=total-maxx;
        
         if(remaining>=maxx) return total;
        
         return (2*remaining+1);
        
    }
};