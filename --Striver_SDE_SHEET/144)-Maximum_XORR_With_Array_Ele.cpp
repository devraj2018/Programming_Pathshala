vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector<int>res;
    for(auto x:queries)
       {
          int num=x[0];
          int maxi=x[1];
          int answer=-1;
          for(int i=0;i<arr.size();i++)
             {
                  if(arr[i]<=maxi)
                     answer=max(answer,num^arr[i]);
             }
          res.push_back(answer);
        }
    return res;
}