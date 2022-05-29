//Using Priority Queue    //    Solution-1

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        
         for(int i=0;i<k-1;i++) pq.pop();
         return pq.top();
     }
};






// Using Own Built Max Heap
//Solution-2
class Solution
{

  
    public:
    //Function to return k largest elements from an array.
     void heapify(int arr[], int n, int i)  
     {
       int largest=i;
       int left= 2*i+1;
       int right= 2*i+2;
    
       if(left<n && arr[largest]<arr[left]) largest=left;
       if(right<n && arr[largest]<arr[right]) largest=right;  
      
       if(largest!=i)
         {
          swap(arr[largest],arr[i]);
          heapify(arr,n,largest);
        }
     }

    
    void buildHeap(int arr[], int n)  
      { 
        for(int i=n/2-1 ;i>=0 ;i--)
            {
              heapify(arr,n,i);
           }
      }
    vector<int> kLargest(int arr[], int n, int k)
    {   vector<int>res;
         buildHeap(arr,n);
         for(int i=0;i<k;i++)
         {
             res.push_back(arr[0]);
             swap(arr[0],arr[n-i-1]);
             heapify(arr,n-i-1,0);
             
         }
         return res;
        
    }
};