class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,int>valid;
        unordered_map<string,int>visited;
        
        for(auto s:wordList) valid[s]++;
        
         visited[beginWord]++;
         queue<pair<string,int>>q;
         q.push({beginWord,0});
        
         int res=0;
         while(!q.empty())
            {
               string curr=q.front().first;
               int time=q.front().second;
               q.pop();

               if(curr== endWord) return time+1;
            
               for(int i=0;i<curr.length();i++)
                   {
                      char ch= curr[i];
                      string news=curr;
                 
                      for(int j=0;j<26;j++)
                        {
                           news[i]=j+'a';
                           if(valid.find(news)!=valid.end() && visited.find(news)==visited.end())
                              {
                                  visited[news]++;
                                  q.push({news,time+1});
                              }
                        }
                      curr[i]=ch;
                   }
            }
        return 0;
     }
};