int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    
    int i=0,j=0;int count=0;
    
    while(i<m && j<n)
    {
         int ele;
         if(row1[i]<=row2[j])
         {
             ele=row1[i];
             i++;
         }
        else{
             ele=row2[j];
             j++;
        }
        count++;
        if(count==k) return ele;
     }
    while(i<m)
    {
        int ele=row1[i];
         i++;
        count++;
        if(count==k) return ele;
    }
     while(j<n)
    {
        int ele=row2[j];
         j++;
        count++;
        if(count==k) return ele;
    }
    return -1;
    
    
    
}