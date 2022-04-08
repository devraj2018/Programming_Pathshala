class Solution {
public:
    
    // ---Method -1 (Brute force O(n^2) By considering all subarray and sum of minimums of all )
    
    
    //Method- 2  -->>   Using stack and by calculation next smaller ele to left and next smaller ele to right
    
    void Next_Smaller(vector<int>&arr,vector<int>&nse,int n)
    {
          stack<int>s;
         
          for(int i=n-1;i>=0;i--)
          {
              
               while(!s.empty() && arr[s.top()]>arr[i])
                   s.pop();
              if(s.empty()) nse[i]=n;
              else
                  nse[i]=s.top();
              
              s.push(i);
          }
    }
    //    Dono mai se ek mai  = wala sign hatana hai to avoid duplicate subarray
     void Prev_Smaller(vector<int>&arr,vector<int>&pse,int n)
    {
          stack<int>s;
          for(int i=0;i<n;i++)
          {
              
               while(!s.empty() && arr[s.top()]>=arr[i])
                   s.pop();
               if(s.empty()) pse[i]=-1;
               else
                  pse[i]=s.top();
              
              s.push(i);
              
          }
     }
    int sumSubarrayMins(vector<int>& arr) {
        long long mod=1e9+7;
        int n=arr.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        Next_Smaller(arr,right,n);
        Prev_Smaller(arr,left,n);
        
        long long ans=0;
        int lcount,rcount;
        for(int i=0;i<n;i++)
        {  lcount= (i-left[i]);
           rcount= (right[i]-i);
          
         ans = ans + lcount*rcount*arr[i];
             
            
        }
        return (int)ans;
    }
};