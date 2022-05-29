class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string> isValid;
        unordered_set<string> visited;
        for(auto x:bank) isValid.insert(x);
        
        if(start==end) return 0;
        queue<pair<string,int>>q;
        q.push({start,0});
        visited.insert(start);
        char canChange[4]={'A','C','G','T'};
        
        while(!q.empty())
           {
             
              string curr= q.front().first;
              int dis=q.front().second;
              q.pop();
            
              if(curr==end) return dis;
            
              for(int i=0;i<curr.length();i++)
                {
                   char prev=curr[i];
                
                  for(int j=0;j<4;j++)
                     {
                       curr[i]=canChange[j];
                    
                       if(isValid.find(curr)!=isValid.end() && visited.find(curr)==visited.end())
                         {   visited.insert(curr);
                          q.push({curr,dis+1});
                         }
                    
                     }
                curr[i]=prev;
                
               }
           }
         return -1;
    }
};