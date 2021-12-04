void tower(int N, int sourcePole,int destinationPole, int auxiliaryPole,int &count,int n,vector<int>&res)
{
      if(0 == N)
        return;

        // Move first n-1 disks from source pole
        // to auxiliary pole using destination as
        // temporary pole
        tower(N - 1, sourcePole, auxiliaryPole,destinationPole,count,n,res);
 
       count++;
       if(count==n)
        {
         res.push_back(sourcePole);
         res.push_back(destinationPole);
        return;
        }

 
       // Move the n-1 disks from auxiliary (now source)
       // pole to destination pole using source pole as
      // temporary (auxiliary) pole
      tower(N - 1, auxiliaryPole, destinationPole, sourcePole,count,n,res);
}
  vector<int> shiftPile(int N, int n){
      vector<int>res;
      int count=0;
      tower(N,1,3,2,count,n,res);
      return res;
    }
