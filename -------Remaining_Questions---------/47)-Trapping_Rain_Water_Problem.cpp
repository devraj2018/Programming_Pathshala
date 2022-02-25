class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2) return 0;
        
        int ans=0;
        int lmax=INT_MIN;
        int rmax=INT_MIN;
        int start=0,end=n-1;
        while(start<=end)
        {
             lmax=max(lmax,height[start]);
            rmax=max(rmax,height[end]);
            
            if(lmax<=rmax)
                ans+= lmax-height[start++];
            else
                ans+= rmax-height[end--];
            
            
        }
        
        return ans;
        
        
    }
};

-----------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n),right(n);
        
        left[0]=height[0];
        right[n-1]=height[n-1];
        
        for(int i=1;i<n;i++)
        {
             left[i]=max(left[i-1],height[i]);
             right[n-i-1]=max(right[n-i],height[n-i-1]);
            
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
             ans+= min(left[i],right[i])-height[i];
            
            
        }
        return ans;
    }
};
