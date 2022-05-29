vector<int> maximumsumSubarray(vector<int> &arr , int n)
{
    int maxSum=INT_MIN;
	int curr_sum=0;
	int start=0,end,s;
	
	for(int i=0;i<arr.size();i++)
	{
		curr_sum+=arr[i];
		
		if(curr_sum>maxSum)
		{   start=s;
			end=i;
			maxSum=curr_sum;
		}
		
		if(curr_sum<0){
			curr_sum=0;
			s=i+1;
		}
		
	}
	vector<int>res;
	for(int i=start;i<=end;i++) res.push_back(arr[i]);
	return res;
	
}
