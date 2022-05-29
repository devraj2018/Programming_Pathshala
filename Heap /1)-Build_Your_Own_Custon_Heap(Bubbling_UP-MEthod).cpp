// Max Heap         
#include<bits/stdc++.h>
using namespace std;
int n=0;
void bubblingUp( vector<int>&arr,int index)
   {   int par;
       if(index&1) par=index/2;
       else par=index/2-1;
       while(index>0  && arr[index] > arr[par])       // 0 Based Indexing 
          {  swap(arr[index], arr[par]);
             index=par;
             if(index&1) par=index/2;
             else par=index/2-1;
         }

         
     
  }
void buildHeap( vector<int>&arr )       // Building from 1st psotion takes nlogn time
   {   n=arr.size();
       for(int i=0;i<n;i++)
        {
          bubblingUp(arr,i);
        }     
  }


int getMax( vector<int>&arr)
{    n=arr.size();
    if(n>=0) return arr[0];
    else cout<<"Heap IsEmpty"<<endl;
    return -1;
}
void insert(int a,vector<int>&arr)
{
	   arr.push_back(a);
      n=arr.size();
	   bubblingUp(arr,n-1);
	
	
}
void maxHeapify(int index,  vector<int>&arr)
{     n=arr.size();
      if(index> n/2) return;
      int largest=index;
      int left=2*index+1;
      int right=2*index+2;
  
      if(arr[largest]<arr[left])
        largest=left;
      if(right<n && arr[largest]<arr[right])
        largest=right;
       
      if(largest!=index)
      {
              swap(arr[largest],arr[index]);
              maxHeapify(largest,arr);

      }
       
 }
void deleteAtIndex( vector<int>&arr,int index)
{    
       n=arr.size();
        
       arr[index]=INT_MAX;
         
       bubblingUp(arr,index); 
        
       swap(arr[0],arr[n-1]);
        arr.pop_back();
       
        maxHeapify(0,arr);                                         //Delete At root Logic


}
int main()
{
      
      vector<int>arr{3,4,0,1,2,7,8,9,5,6};
      n=10;
      buildHeap(arr);
      cout<<getMax(arr)<<endl;
     
      insert(100,arr);
      cout<<getMax(arr)<<endl;
      deleteAtIndex(arr,0);
      deleteAtIndex(arr,0);
      cout<<getMax(arr)<<endl;
       
      
      
 
}