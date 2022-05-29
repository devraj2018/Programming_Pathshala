/*

*/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n=board.size();
        vector<int>res;
        res.push_back(0);
        
        bool first=true;
        for(int i=n-1;i>=0;i--)
        {
            if(first)
            {
                for(int j=0;j<n;j++) res.push_back(board[i][j]);
                
            }
            else
            {
                 for(int j=n-1;j>=0;j--) res.push_back(board[i][j]);
                 
            }
            first=!first;
         }
        
        vector<bool>visited(n*n+1,false);
        visited[1]=true;
        
        queue<pair<int,int>>q;
        q.push({1,0});
        while(!q.empty())
        {
            int curr=q.front().first;
            int moves=q.front().second;
            q.pop();
            
            if(curr== n*n) return moves;
            
            for(int i=1;i<=6;i++)
            {
                
                int new_curr=curr+i;
                
                if(new_curr>n*n || visited[new_curr] ) continue;
                
                if( res[new_curr]==-1 )
                    {
                       q.push({new_curr,moves+1});
                       visited[new_curr]=true;
                    }
                else if(res[new_curr]!=-1  && visited[res[new_curr]]==false)
                {  q.push({res[new_curr],moves+1});
                   visited[res[new_curr]]=true;
                   visited[new_curr]=true;
                }
                
            }
            
            
            
        }
        return -1;
        
        
    }
};