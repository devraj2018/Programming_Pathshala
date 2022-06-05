class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
          vector<int> res;
          
          for(int i=0;i<n;i++)
          {
              int index= arr[i]%n;
              arr[index]+=n;
          }
          for(int i=0;i<n;i++)
          {
              if(arr[i]>=2*n) res.push_back(i);
          }
          if(res.size()==0) return {-1};
          return res;
    }
};