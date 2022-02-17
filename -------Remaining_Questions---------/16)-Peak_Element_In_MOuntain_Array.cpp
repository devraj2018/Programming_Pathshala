class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int n=arr.size();
        int low=0,high=n-1;
        
        while(low<=high)
        {    int mid= high-(high-low)/2;
             int prev=max(0,mid-1);
             int next=min(n-1,mid+1);
            
            if(arr[prev]<arr[mid] && arr[mid]>arr[next])
                return mid;
            if(arr[prev]<arr[mid] && arr[mid]<arr[next])
                low=mid+1;
            else
                high=mid-1;
         }
        return -1;
    }
};