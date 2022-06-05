================================================================================================
=============================== O(nlogn)Time and O(n) Space ================================
================================================================================================

long long int merge(long long arr[],long long low,long long mid,long long high)
{
    long long int count=0;
    long long n1=mid-low+1;
    long long n2=high-mid;
    long long arr1[n1];
    long long arr2[n2];
    
    for(long long i=0;i<n1;i++) arr1[i]=arr[low+i];
    for(long long i=0;i<n2;i++)  arr2[i]=arr[mid+i+1];
    
    long long i=0,j=0,k=low;
    
    while(i<n1 && j<n2)
    {
         if(arr1[i]<=arr2[j]) arr[k++]=arr1[i++];
         else {
            arr[k++]=arr2[j++];
            count += (n1-i); 
            }
     }
     while(i<n1) arr[k++]=arr1[i++];
     while(j<n2) arr[k++]=arr2[j++];
     
     return count;
    
}
long long int inversion(long long arr[],long long low,long long high)
{
     if(low>=high) return 0;
     long long int count=0;
     long long mid= low+(high-low)/2;
    
     count+= inversion(arr,low,mid); 
     count+= inversion(arr,mid+1,high);
     count+= merge(arr,low,mid,high);
     return count;     
}

long long int inversionCount(long long arr[], long long N)
{
   return inversion(arr,0,N-1);
}


================================================================================================
=============================== O(n*n)Time and O(1) Space ======================================
================================================================================================

long long int inversionCount(long long arr[], long long N)
{
   long long int ans=0;
   
   for(long long i=0;i<N;i++)
   {
       for(long long j=i+1;j<N;j++)
       {
           if(arr[j]<arr[i]) ans++;
       }
   }
   return ans;
}