class Solution {
public:
    double pow(double x,int n)
    {   if(n==0)  return 1;
        double ans=pow(x,n/2);
        
        if(n&1) return x*ans*ans;
        return ans*ans;
    }
    double pown(double x,int n)
    {
        if(n==0) return 1;
        double ans=pown(x,n/2);
        
        if(n&1) return 1/x*ans*ans;
        return ans*ans;
    }
    double myPow(double x, int n) {
        if(x==1) return x;
        if(n>=0) return pow(x,n);
        return (pown(x,n));
        
    }
};