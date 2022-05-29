class Solution{
     public:
       string solve(string A) {

          int n=A.length();
          queue<char>q;
          vector<int>freq(26,0);
          string res="";
          for(int i=0;i<n;i++)
               {
                  while(!q.empty() && q.front()== A[i]) q.pop();  // To remove Similar ele to curr_ele

                  while(!q.empty() && freq[q.front()-'a']>1) q.pop(); //To remove whose freq>1

                  if(freq[A[i]-'a']==0) q.push(A[i]);    // Push Only when freq=0,bcz that's way we can store distinct ele

                  freq[A[i]-'a']++;  // Increse freq here

                  if(!q.empty()) res.push_back(q.front());
                  else res+="#";

               }
             return res;
             

}
 



}