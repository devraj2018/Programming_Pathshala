/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int findPivot(MountainArray &mountainArr,int n,int target)
    {
          int mid,low=0,high=n-1;
         
          while(low<=high)
          {      mid= high -(high-low)/2;
               int prev=mountainArr.get(max(mid-1,0));
               int next=mountainArr.get(min(mid+1,n-1));
               int midele=mountainArr.get(mid);
              
              if(prev <midele && midele> next)
              {
                  return mid;
              }
             else if(prev<midele && midele<next)
                 low=mid+1;
             else 
                 high=mid-1;
            
          }
        return 0;
        
    }
    int lsearch(MountainArray &mountainArr,int s,int e,int target)
    {
              int mid,low=0,high=e;
				  while(low<=high)
				     {
						    mid= high -(high-low)/2;
                            int midele=mountainArr.get(mid);
					    	if(midele==target)
						      {
							      return mid;
					         }
						     else if(midele>target)
							      high=mid-1;
                             else
                                low=mid+1;
                          
				    } 
        return -1;
        
    }
     int rsearch(MountainArray &mountainArr,int s,int e,int target)
    {
              int mid,low=0,high=e;
				  while(low<=high)
				     {
						    mid= high -(high-low)/2;
                            int midele=mountainArr.get(mid);
					    	if(midele==target)
						      {
							      return mid;
					         }
						     else if(midele>target)
							     low=mid+1;
                             else
                                 high=mid-1;
                          
				    } 
         return -1;
        
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int pivot=findPivot(mountainArr, n,target);
        
       
        
        int lft=lsearch(mountainArr,0,pivot,target);
        int rgt=rsearch(mountainArr,pivot+1,n-1,target);
        
        
        if(lft==-1)
            return rgt;
        return lft;
        
    }
};