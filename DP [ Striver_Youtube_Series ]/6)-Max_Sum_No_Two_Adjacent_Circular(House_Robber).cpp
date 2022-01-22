long long int Robber(vector<int>&nums)     // Same as normal House Robber
{
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        
       
        long long int a=nums[0];
        long long int b=max(nums[0],nums[1]);
        long long int c;
        
        for(int i=2;i<n;i++)
        {
            c=max(a+nums[i],b);
            a=b;
            b=c;
            
         }
        return c;
        
}
long long int houseRobber(vector<int>& nums)
{
        int n=nums.size();
        if(n==1) return nums[0];
        
         vector<int>nums1,nums2;   //Just we need to create two array
        for(int i=0;i<n;i++)      // 1-> Having all element except first element
          {                        // 2-> Having all element except last element
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
          }

      return max(Robber(nums1),Robber(nums2));
    
        
}