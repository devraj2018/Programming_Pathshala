class Solution {
public:
                                         // O(n) Space approach //
    int trap(vector<int>& heights) {
        int n=heights.size();
        vector<int>lmax(n,0);
        vector<int>rmax(n,0);
        lmax[0]=heights[0];rmax[n-1]=heights[n-1];
        for(int i=1;i<n;i++)
        {
             lmax[i]=max(lmax[i-1],heights[i]);
             rmax[n-i-1]=max(rmax[n-i],heights[n-i-1]);
            
            
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans+= min(lmax[i],rmax[i])-heights[i];
        }
        return ans;
        
        
    }
    
    int trap(vector<int>& heights)         // O(1) Space solution
    {   
        int n=heights.size();
        int lmax=0,rmax=0;
        int ans=0;
        int start=0,end=n-1;
        while(start<=end)
        { lmax=max(lmax,heights[start]);
           rmax=max(rmax,heights[end]);
            if(lmax<=rmax)
             {
               ans+= lmax-heights[start];
               start++;
             }
           else
            {
             ans+=rmax-heights[end];
             end--;
             }
           
        }
        return ans;
        
    }
    
};

