bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {

  sort(arrive.begin(),arrive.end());
  sort(depart.begin(),depart.end());

  int i=0,j=0;
  
  int curr_required=0;
  int maxx=0;
  while(i< arrive.size() && j<arrive.size())
  {
       if(arrive[i]<depart[j])
       {
            curr_required++;
            i++;
       }
       else {
           curr_required--;
           j++;
       }
       maxx=max(maxx,curr_required);
       if(maxx>K) return false;
  
  }
  return true;

}
