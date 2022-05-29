
class Solution {
public:
    int search(vector<int>&A, int target) {
        
        int n=A.size();
        
        int low=0,high=n-1;
        
        while(low<high)
        {
            int mid= (low+high)>>1;
            if(A[mid]>A[high]) low=mid+1;
            else
                high=mid;
        }
        
        int rotation=low;
        low=0,high=n-1;
        
        while(low<=high)
        {
             int mid= (low+high)>>1;
             int realmid= (mid+rotation)%n;
            
            
             if(A[realmid]==target) return realmid;
             if(A[realmid]<target)
             {
                 low=mid+1;
             }
            else
                high=mid-1;
            
        }
        return -1;
    }
};
---------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int start=0,end=n-1;
        int mid;
        while(start<end)
        {
             mid= start +(end-start)/2;
            
             if(nums[mid]>nums[end])
                 start=mid+1;
             else
                 end=mid;
        }
        
        int midi=start;
       // cout<<midi<<" <-MIDI ";
        start=0,end=midi-1;
        
        int ans=-1;
        while(start<=end)
        {
             mid= start +(end-start)/2;
            
             if(nums[mid]==target)
             { 
                  ans=mid;
                  break;
                 
             }
               
             if(nums[mid]>target)
                 end=mid-1;
             else
                 start=mid+1;
        }
       // cout<<ans<<" <-AnS";
        if(ans!=-1) return ans;
         start=midi,end=n-1;
         while(start<=end)
        {
             mid= start +(end-start)/2;
            
             if(nums[mid]==target)
             { 
                  ans=mid;
                  break;
                 
             }
               
             if(nums[mid]>target)
                 end=mid-1;
             else
                 start=mid+1;
        }
         //cout<<ans<<" <-AnS";
        return ans;
  }
};
