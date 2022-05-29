class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        kk=k;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
            {   pq.push(nums[i]);
                if(pq.size()>kk) pq.pop();
            }
         }
      int add(int val) {
             pq.push(val);
             if(pq.size()>kk) pq.pop();
             return pq.top();
    }
};


  /*
 class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
      
       vector<int>res;
       priority_queue<int,vector<int>,greater<int>>pq;
       
       for(int i=0;i<n;i++)
       {
           pq.push(arr[i]);
           if(pq.size()<k)  res.push_back(-1);
           else{ 
                  if(pq.size()>k) pq.pop();
               
                 res.push_back(pq.top());
                }
           
           
       }
       return res;
    }
};
*/