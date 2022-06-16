int calculateMinPatforms(int at[], int dt[], int n) {
    
	int arr[2400]={0};
	 for(int i=0;i<n;i++)
	 {
		  arr[at[i]]++;
		  arr[dt[i]+1]--;
		 
	 }
	int ans=-1;
	int curr_req=0;
	for(int i=0;i<=2399;i++)
	{
		curr_req+=arr[i];
		ans=max(ans,curr_req);
	}
	return ans;
	
	
}