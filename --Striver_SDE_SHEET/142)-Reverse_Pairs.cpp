#include <bits/stdc++.h> 
long long int merge(vector<int>&arr,long long low,long long mid,long long high)
{
    long long int count=0;
    
    long long n1=mid-low+1;
    long long n2=high-mid;
    
    long long arr1[n1];
    long long arr2[n2];
    
    for(long long i=0;i<n1;i++)
    {
        arr1[i]=arr[low+i];
    }
    for(long long i=0;i<n2;i++)
    {
        arr2[i]=arr[mid+i+1];
    }
    
    long long j=0;
     for(int i=0;i<n1;i++){
            while(j<n2 && (arr1[i] > 2LL*arr2[j])){
                j++;
            }
            count += j;
        }
    
    long long i=0,k=low;
    j=0;
    
    while(i<n1 && j<n2)
    {
        
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            i++;k++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;k++;
           
        }
     }
     while(i<n1) arr[k++]=arr1[i++];
     while(j<n2) arr[k++]=arr2[j++];
     
     return count;
      
}
long long int inversion(vector<int> &arr,long long low,long long high)
{
     if(low>=high) return 0;
     
     long long int count=0;
     long long mid= low+(high-low)/2;
    
    count+= inversion(arr,low,mid); 
    count+= inversion(arr,mid+1,high);
    count+= merge(arr,low,mid,high);
    
    return count;
     
}
int reversePairs(vector<int> &arr, int n){
	long long ans=inversion(arr,0,n-1);
    return (int)ans;
}