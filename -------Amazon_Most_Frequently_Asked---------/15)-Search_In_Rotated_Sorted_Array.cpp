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