class Solution {
	public:
		string FirstNonRepeating(string A){
		   string res="";
		   int n=A.length();
		   
		   queue<char>q;
		   unordered_set<char>s;
		   
		   vector<int>freq(26,0);
		   for(int i=0;i<n;i++)
		       {
		            while(!q.empty() && A[i]==q.front()) q.pop();
		           
		            while(!q.empty() && freq[q.front()-'a']>1) q.pop();
		           
		            if(s.find(A[i])==s.end())
		              {
		                  s.insert(A[i]);
		                  q.push(A[i]);
		              }
		            freq[A[i]-'a']++;
		            if(q.empty()) res+="#";
		            else res.push_back(q.front());
		       }
		   return res;
		}

};