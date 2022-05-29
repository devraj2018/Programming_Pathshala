/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {                // ---------------   BETTER APPROACH     ------------------//
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int start=0,n=mountainArr.length();
        int end=n-1;
        int peakIndex;
        
        int mid;
        while(start<end)
        {   mid= (start+end)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)) start=mid+1;
            else end=mid;
        }
        
        peakIndex=start;
        
        start=0,end=peakIndex;
        while(start<=end)
           {
             mid= (start+end)/2;
             int midele= mountainArr.get(mid);
             if(midele==target) return mid;
             if(midele>target)  end=mid-1;
             else  start=mid+1;
           }
        
        start=peakIndex+1,end=n-1;
        while(start<=end)
           {
              mid= (start+end)/2;
              int midele= mountainArr.get(mid);
              if(midele==target) return mid;
              if(midele>target) start=mid+1;
              else  end=mid-1;
          }
        return -1;
     }
};



















---------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------

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
    int max_index=-1;
    int max_ele;
    void Bsearch(int target, MountainArray &mountainArr,int n)
    {
        
        int s=0,e=n-1;
        int mid;
        while(s<=e)
        {    mid= (s+e)/2;
              int prev=mountainArr.get(max(mid-1,0));
              int midele=mountainArr.get(mid);
               int next=mountainArr.get(min(mid+1,n-1));
            
             if(prev<=midele && midele>=next) 
             {
                 max_index=mid;
                 max_ele=midele;
                 return;
             }
            else if(prev<=midele)
            {
                s=mid+1;
            }
         else
             e=mid-1;
            
         }
      
      
    }
    int lsearch(int target, MountainArray &mountainArr,int s,int e)
    {
         int mid;
        while(s<=e)
        {     mid= (s+e)/2;
              int midele=mountainArr.get(mid);
            
              if(midele==target) return mid;
               if(midele>target) e=mid-1;
               else s=mid+1;
        }
        return -1;
        
        
    }
    int rsearch(int target, MountainArray &mountainArr,int s,int e)
    {
         int mid;
        while(s<=e)
        {     mid= (s+e)/2;
              int midele=mountainArr.get(mid);
            
              if(midele==target) return mid;
               if(midele>target) s=mid+1;
               else e=mid-1;
        }
        return -1;
        
        
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n=mountainArr.length();
        Bsearch(target,mountainArr,n);
        int first=mountainArr.get(0);
        int last=mountainArr.get(n-1);
        
      
        
        if(first<=target && target<= max_ele)
        {   int ans=lsearch(target,mountainArr,0,max_index);
            if(ans!=-1) return ans;
        }
        
         if(max_ele>=target && target>=last)
         {
              int ans=rsearch(target,mountainArr,max_index+1,n-1);
              if(ans!=-1) return ans;
         }
        return -1;
        
        
        
    }
};