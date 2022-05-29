class Solution{
public:
    int minThrow(int N, int arr[]){
       vector<int>nums(31,-1);
       
       for(int i=0;i<2*N;i+=2)
       {
           nums[arr[i]]=arr[i+1];
       }
       
       queue<pair<int,int>>q;
       vector<bool>visited(31,false);
       visited[1]=true;
       
       q.push({1,0});
       while(!q.empty())
       {
            int curr=q.front().first;
            int moves=q.front().second;
            
            q.pop();
            
            
            if(curr==30) return moves;
            
            for(int i=1;i<=6;i++)
            {
                int new_pos= curr+i;
                
                if(new_pos>30 ||visited[new_pos]) continue;
                
                if(nums[new_pos]==-1)
                 {
                     q.push({new_pos,moves+1});
                     visited[new_pos]=true;
                 }
                else if(visited[nums[new_pos]]==false)
                {
                    q.push({nums[new_pos],moves+1});
                     visited[nums[new_pos]]=true;
                }
                
            }
           
           
       }
       return 0;
    }
};