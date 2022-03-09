class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        
        unordered_map<string,int>valid;
        for(auto s:wordList) valid[s]++;
        
        if(valid.find(endWord)==valid.end()) return ans;
        
         queue<vector<string>>q;
         q.push({beginWord});
        
         bool found=false;
         while(!q.empty())
            {  
              int size=q.size();
             
              for(int i=0;i<size;i++)
                 {
                     vector<string>curr_path=q.front();
                     q.pop();

                     if(curr_path.back() == endWord)
                     {
                         ans.push_back(curr_path);
                         found=true;
                         continue;
                     }
                  
                    string curr=curr_path.back();
                    valid.erase(curr);                    //.  Imporatnt to Avoid INfinite LOOP ,If curr_path is shortest path,
                                                         // Then we can remove curr for next larger paths
                    for(int i=0;i<curr.length();i++)
                         {
                            char ch= curr[i];
                            string news=curr;
                          
                            for(int j=0;j<26;j++)
                                {
                                    news[i]=j+'a';
                                    if(valid.find(news)!=valid.end() )
                                       {
                                         curr_path.push_back(news);
                                         q.push(curr_path);
                                         curr_path.pop_back();
                                       }
                                }
                            curr[i]=ch;
                        }
                      
                  }
              if(found) break;    // If shortest path found means all transformation are that level, and we took that 
                                   // So break from here ,bcz after this all paths are larger than shortest path
              }
        
        return ans;
        
        
    }
};