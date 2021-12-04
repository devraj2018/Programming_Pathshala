    
                   // -----------This method is O(n) time method--Optimal approach------------//

    //Here we check in how many subarray arr[i] will participate,then multiply that with arr[i],so that//
    //--We can find about how much sum in contributed by arr[i] in all subarrays//
    long long mod=1e9+7; 
    long long subarraySum(long long a[], long long n)
    {  long long ans=0;
       
       for(long long i=0;i<n;i++)
       {
             long long csum= ((i+1)%mod * (n-i)%mod * a[i]%mod)%mod;
             
             ans= (ans%mod + csum%mod)%mod;
                 
       }
       return ans;
       
    }

    // -------O(n^2) method ,Constant space --Not optimal But brute force to start in interview//

      long long subarraySum(long long a[], long long n)
    {  long long ans=0;
       
       for(long long i=0;i<n;i++)
       {   long long csum=0;
             for(long long j=i;j<n;j++)
             {
                     csum= (csum%mod + ((i+1)%mod * (n-i)%mod * a[i]%mod)%mod )%mod;
             
                     ans= (ans%mod + csum%mod)%mod;

             }
                 
       }
       return ans;
       
    }