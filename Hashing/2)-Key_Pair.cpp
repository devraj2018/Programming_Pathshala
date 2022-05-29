class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	     unordered_set<int>s;
	     
	     for(int i=0;i<n;i++)
	     {
	         
	          if(s.find(x-arr[i])!=s.end())
	            return true;
	         s.insert(arr[i]);
	         
	     }
	     return false;
		 
	}
};