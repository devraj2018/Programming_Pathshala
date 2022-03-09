class Solution{
    public:
     
    int findPlatform(int arr[], int dep[], int n)
    {     
           vector<int>temp(2400,0);
           for(int i=0;i<n;i++)
             {   temp[arr[i]]++;
                 temp[dep[i]+1]--;
             }
           
           int maxx=0;
           int currsum=0;
           for(int i=0;i<=2400;i++)
               {
                 currsum+=temp[i];
                 maxx=max(maxx,currsum);
               }
           return maxx;
    }
};