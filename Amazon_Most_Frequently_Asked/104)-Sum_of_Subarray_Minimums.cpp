class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>NSER(n,n),NSEL(n,-1);
        
        stack<int>s;
        for(int i=0;i<n;i++)
        {
             while(!s.empty() && arr[s.top()]>arr[i])
                 s.pop();
            
             if(!s.empty()) NSEL[i]=s.top();
            
            s.push(i);
        }
        stack<int>s1;
         for(int i=n-1;i>=0;i--)
        {
             while(!s1.empty() && arr[s1.top()]>=arr[i])
                 s1.pop();
            
             if(!s1.empty()) NSER[i]=s1.top();
            
            s1.push(i);
        }
        
        long long ans=0;
        int mod=1e9+7;
        
        for(int i=0;i<n;i++)
        {
            ans= (ans%mod + (long long)(i-NSEL[i])*((NSER[i]-i)*arr[i]))%mod;
            
        }
        return (int)ans;
        
    }
};