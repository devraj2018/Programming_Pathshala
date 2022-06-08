int search(int* nums, int n, int target) {
    
         
         int low=0,high=n-1;
         int mid;
        while(low<high)
        {
            mid= low+(high-low)/2;
            
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid;
        }
        
        int minindex=low;
        
        low=0,high=n-1;
        while(low<=high)
        {
               mid= low+(high-low)/2;
               int realmid = (mid+minindex)%n;
            
              if(nums[realmid]==target) return realmid;
            
              if(nums[realmid]>target) high=mid-1;
              else low=mid+1;
            
        }
        return -1;

}