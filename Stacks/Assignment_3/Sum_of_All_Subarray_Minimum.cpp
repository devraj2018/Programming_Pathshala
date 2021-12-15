class Solution {
public:
    
    // ---Method -1 (Brute force O(n^2) By considering all subarray and sum of minimums of all )
    
    
    //Method- 2  -->>   Using stack and by calculation next smaller ele to left and next smaller ele to right
    
    void next_smaller_to_left(vector<int>&arr,vector<int>&left)
    {  
        stack<pair<int,int>>s;
        s.push({arr[0],0});                   
        for(int i=1;i<arr.size();i++)
        {
             while(!s.empty() && s.top().first>arr[i])// Smaller than or equal to, to avoid duplicate subarray
                 s.pop();
            
             if(!s.empty())
                 left[i]=s.top().second;
            
            s.push({arr[i],i});
            
        }
      
    }
     void next_smaller_to_right(vector<int>&arr,vector<int>&right)
    {  int n=arr.size();
        stack<pair<int,int>>s;
        s.push({arr[n-1],n-1});                   
        for(int i=n-2;i>=0;i--)
        {
             while(!s.empty() && s.top().first>=arr[i])
                 s.pop();
            
             if(!s.empty())
                 right[i]=s.top().second;
            
             s.push({arr[i],i});
            
        }
    
    }
    int sumSubarrayMins(vector<int>& arr) {
        long long mod=1e9+7;
        int n=arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        next_smaller_to_left(arr,left);
        next_smaller_to_right(arr,right);
        
        long long ans=0;
        int lcount,rcount;
        for(int i=0;i<n;i++)
        {  lcount= (i-left[i]);
           rcount= (right[i]-i);
          
         ans = (ans%mod + ((long long)lcount*rcount*arr[i])%mod)%mod;
             
            
        }
        return (int)ans;
    }
};