class Solution {
public:
    int mySqrt(int x) {
        
        long long mid,low=0,high=(long long)x;
        long long ans;
        while(low<=high)
        {
            mid= high -(high-low)/2;
            
            if(mid*mid == x)
                return (int)mid;
            if(mid*mid < x)
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
             
            
        }
        return (int)ans;
        
    }
};