class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	   int row=-1;
	   int max_one=0;
	   
	   for(int i=0;i<n;i++)
	   {
	       auto lb=lower_bound(arr[i].begin(),arr[i].end(),1);
	       int one=m - (lb-arr[i].begin());
	       
	       if(one>max_one)
	       {
	           max_one=one;
	           row=i;
	       }
	      
	   }
	   return row;
	   
	}

};