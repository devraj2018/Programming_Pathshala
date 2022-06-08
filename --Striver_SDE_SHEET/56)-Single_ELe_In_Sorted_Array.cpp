int uniqueElement(vector<int> arr, int n)
{
	int xorr=0;
    for(int i=0;i<n;i++)
    {
        xorr^=arr[i];
    }
    return xorr;
}
