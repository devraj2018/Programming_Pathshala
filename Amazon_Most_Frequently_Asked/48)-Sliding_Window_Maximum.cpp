
------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------|||||||||  Deque   O(n) Time and O(k) Space Solution   ||||||||||--------------------------
---------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
        }
       
        vector<int>res;
        res.push_back(nums[dq.front()]);
        
        for(int i=k;i<nums.size();i++)
           {
              while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            
              dq.push_back(i);
              if(i-dq.front() >=k) dq.pop_front();   // Excess Element
            
              res.push_back(nums[dq.front()]);
         }
        return res;
        
    }
};


------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------|||||||||  Priority_queue  O (n*logk) Time and O(k) Space   ||||||||||--------------------------
---------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>>pq;
        vector<int>res;
        for(int i=0;i<k;i++)  pq.push({nums[i],i});
         
        res.push_back(pq.top().first);
        
        for(int i=k;i<nums.size();i++)
          {
              pq.push({nums[i],i});
              while(pq.top().second <= (i-k))  pq.pop();    //  Out of window pop
            
              res.push_back(pq.top().first);
          }
        return res;
        
        
    }
};


