class Solution {
public:
// Array is 20,25,27,33,65,70 //
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;
        
        int maxE=*max_element(nums.begin(),nums.end());
        int minE=*min_element(nums.begin(),nums.end());
        
        int gap=max((maxE-minE)/(n-1),1);
        int m=(maxE-minE)/gap +1;
        vector<int>MAXX(m,INT_MIN);
        vector<int>MINN(m,INT_MAX);
        
        for(auto X:nums)
        {
            int bucket_no= (X-minE)/gap;
            
            if(X<MINN[bucket_no]) MINN[bucket_no]=X;
            if(X>MAXX[bucket_no]) MAXX[bucket_no]=X;
            

            
            
        }
        
        int pre=MAXX[0];
        int ans=0;
        
        for(int i=1;i<m;i++)
        {
             if(MAXX[i]==INT_MIN)
                 continue;
             ans=max(ans,MINN[i]-pre);
             pre=MAXX[i];
            
            
        }
        return ans;
        
        
    }
};