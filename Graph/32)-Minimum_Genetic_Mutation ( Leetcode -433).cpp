class Solution {
public:
    int minMutation(string beginWord, string endWord, vector<string>& bank) {
        
        if(beginWord == endWord) return 0;
        
        unordered_set<string> valid;
        unordered_set<string> visited;
        
        for(auto s:bank) valid.insert(s);
        
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        visited.insert(beginWord);
        
        char possible[4]={'A','C','G','T'};
        
        
        while(!q.empty())
        {
             string currWord=q.front().first;
             int time = q.front().second;
            
             q.pop();
            
             if(currWord == endWord) return time;
             
             for(int i=0;i<8;i++)
             {
                  char ch= currWord[i];
                  
                  for(int j=0;j<4;j++)
                  {
                       currWord[i]=possible[j];
                       
                       if(valid.find(currWord)!= valid.end() && visited.find(currWord)==visited.end())
                           {
                              q.push({currWord,time+1});
                              visited.insert(currWord);
                            
                       
                           }
                      
                  }
                 currWord[i]=ch;
            }
        }
        return -1;
        
    }
};