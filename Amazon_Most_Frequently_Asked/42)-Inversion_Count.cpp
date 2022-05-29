class Solution{
  public:
   long long int merge(long long arr[],long long start,long long mid,long long end)
       {
             long long int inversion=0;
             long long n1= mid-start+1;
             long long n2= end-mid;
             long long first[n1],second[n2];
    
             for(long long i=0;i<n1;i++) first[i]=arr[start+i];
    
             for(long long i=0;i<n2;i++) second[i]=arr[mid+i+1];
    

    
             long long i=0,j=0,k=start;
    
              while(i<n1 && j<n2)
                {
                    if(first[i]<=second[j])
                       {
                          arr[k]=first[i];
                          i++; k++;
                       }
                   else
                      {
                          arr[k]=second[j];
                          inversion= inversion+(n1-i);
                          j++;
                          k++;
                      }
                }
              while(i<n1) arr[k++]=first[i++];
              while(j<n2) arr[k++]=second[j++];
         
            return inversion;
     
}
long long int mergeSort(long long arr[],long long start,long long end)
{
     long long int ans=0;
     
     
     if(start<end)
     {
          long long mid= start +(end-start)/2;
          
           ans+=mergeSort(arr,start,mid);
           ans+=mergeSort(arr,mid+1,end);
           
           ans+= merge(arr,start,mid,end);
         
     }
     return ans;
   
}
long long int inversionCount(long long arr[], long long N)
{
    return mergeSort(arr,0,N-1);
}

};