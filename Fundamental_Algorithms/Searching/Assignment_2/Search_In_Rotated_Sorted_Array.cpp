class Solution {
public:
     int findminindex(vector<int> arr,int n)
       {     int start=0;int end=n-1;
             while(start<=end)
               {   int mid=start+ (end-start)/2;
                   int next=(mid+1)%n;
                   int prev=(mid+n-1)%n;
            
                   if(arr[mid]<arr[next] && arr[mid]<arr[prev])
                       return mid;
                   else if( arr[mid]<arr[end] )
                       end=mid-1;
                   else
                       start=mid+1;
            
               }   
      return 0;
     }
    int binarySearch(vector<int> arr,int target,int first,int last)
    {    
            while(first<=last)
               {
                int mid=first+ (last-first)/2; 
                if(arr[mid]==target)
                    return mid;
                else if(arr[mid]>target)
                    last=mid-1;
                else 
                    first=mid+1;
               }
        
       return -1;  
         
    }
    
   int search(vector<int>& nums, int target) {
        int index=findminindex(nums,nums.size());
        int ans1=binarySearch(nums,target,0,index-1);
        int ans2=binarySearch(nums,target,index,nums.size()-1);
        
        if(ans1==-1)
            return ans2;
       
         return ans1;
        
        
    }
};