--------------------------------    (n) Time and Space is O(2400)==O(1) -------------------------------------------
_______________________________________________________________________________________________________________________


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

--------------------------------    (n*2400)Time and Space is O(2400)==O(1) -------------------------------------------
_______________________________________________________________________________________________________________________

int calculateMinPatforms(int at[], int dt[], int n) {
      
     int platform[2360]={0};
     int maxx=0;
     for(int i=0;i<n;i++)
     {
          for(int j=at[i];j<=dt[i];j++)
          {
              platform[j]++;
              maxx=max(maxx,platform[j]);
          }
         
     }
    return maxx;
    
}

--------------------------------    (n*logn)Time and Space is O(1) ----------------------------------------------------
_______________________________________________________________________________________________________________________


int calculateMinPatforms(int at[], int dt[], int n) {
      
     sort(at,at+n);
         sort(dt,dt+n);
    
    int maxx=0;
    int platform_needed=0;
    
    int i=0,j=0;
    while(i<n && j<n)
    {
         if(at[i]<=dt[j])
         {
             platform_needed++;
             i++;
         }
        else
        {
            platform_needed--;
            j++;
        }
        maxx=max(maxx,platform_needed);
        
    }
    return maxx;
    
}