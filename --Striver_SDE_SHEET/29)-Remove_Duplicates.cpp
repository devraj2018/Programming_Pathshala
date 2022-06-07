int removeDuplicates(vector<int> &arr, int n) {
	
    int i=0,j=0;
    
    for(j=0;j<n;)
    {
        int curr=arr[j];
        while(j<n && curr==arr[j])
            j++;
        
        swap(arr[i],arr[j-1]);
        i++;
        
    }
    return i;
    
}