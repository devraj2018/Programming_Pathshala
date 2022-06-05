================================================================================================
=============================== O(n)Time and O(2400)=O(1) Space ================================
================================================================================================
class Solution{
    public:
    
    int findPlatform(int arr[], int dep[], int n)
    {
        int line[2400]={0};
        for(int i=0;i<n;i++)
           {
            line[arr[i]]++;
            line[dep[i]+1]--;
           }
        
        int count=0;
        int maxx=0;
        for(int i=0;i<2400;i++)
        {
            count+=line[i];
            maxx=max(maxx,count);
        }
        return maxx;
    }
};


================================================================================================
=============================== O( n*logn )Time and O(1) Space =================================
================================================================================================
class Solution{
    public:
  
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
         int count=0;
        
         int i=0,j=0;
         int res=0;
        
         while(i<n && j<n)
             {
                if(arr[i]<=dep[j])
                  {
                     count++;
                     i++;
                  }
                else
                  { 
                       j++;
                       count--;
                  }
             res=max(res,count);
          
        }
        return res;
    }
};