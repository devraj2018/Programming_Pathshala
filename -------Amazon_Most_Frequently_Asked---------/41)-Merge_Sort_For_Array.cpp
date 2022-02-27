class Solution
{
    public:
    void merge(int arr[], int left, int mid, int right)
    {
         int n1=mid-left+1;
         int n2=right-mid;
         
         int first[n1],second[n2];
         
         for(int i=0;i<n1;i++)  first[i]=arr[left+i];
         
         for(int i=0;i<n2;i++) second[i]=arr[mid+i+1];
         
         int i=0,j=0,k=left;
         
         while(i<n1 && j<n2)
         {
              if(first[i]<=second[j]) {
                  arr[k]=first[i];
                  k++;i++;
              }
              else {
                  arr[k]=second[j];
                  k++;j++;
              }
             
         }
         while(i<n1) arr[k++]=first[i++];
         while(j<n2) arr[k++]=second[j++];
           
    }
    public:
    void mergeSort(int arr[], int left, int right)
    {
        if(left<right)
        {
             int mid= (left+right)/2;
             
             mergeSort(arr,left,mid);
             mergeSort(arr,mid+1,right);
             
             merge(arr,left,mid,right);
             
        }
    }
};