int minSwap(int arr[], int n, int k) {
      
        int countele=0;         //Which are less than and equa to k
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k) countele++;
        }
        
        int maxc=0;           //In every window of total ele which is less than or equal to K -->Find max
        int cnt_current=0;    //Every window of size equal to countele 
        int windowsize=countele;
        for(int i=0;i<countele;i++)
        { 
            if(arr[i]<=k)
             cnt_current++;
            
        }
        maxc=cnt_current;
        for(int i=countele;i<n;i++)
        { 
            if(arr[i]<=k)
             cnt_current++;
             if(arr[i-windowsize]<=k)
             cnt_current--;
             
             maxc=max(maxc,cnt_current);
            
        }
        return windowsize-maxc;
        
        
      
    }