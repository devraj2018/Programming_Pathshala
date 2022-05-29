void helper(TreeNode<int> *root,unordered_map<int,long long>&mp,int &maxx,int &minn,int vh)
{
	 if(root==NULL)
         return;
      maxx=max(maxx,vh);minn=min(minn,vh);
	 mp[vh]+=root->data;
    helper(root->left,mp,maxx,minn,vh-1);
    helper(root->right,mp,maxx,minn,vh+1); 

 	
}
vector< long long >  verticalSum(TreeNode<int> *root) {
    vector<long long >res;
	unordered_map<int,long long>mp;
	int maxx=INT_MIN,minn=INT_MAX;
	helper(root,mp,maxx,minn,0);
	for(int i=minn;i<=maxx;i++)
	{
		res.push_back(mp[i]);
	}
	return res;
	
}
====================================================================
====================================================================
====================================================================


class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        vector <int> res;
        int maxx=INT_MIN,minn=INT_MAX;
        unordered_map<int,int>mp;
        queue<pair<Node* ,int>>q;
        if(root==NULL) return res;
        q.push({root,0});
        while(!q.empty())
        {
             int size=q.size();
             for(int i=1;i<=size;i++)
             {
                 Node* curr=q.front().first;
                 int hd=q.front().second;
                 q.pop();
                 maxx=max(maxx,hd);minn=min(minn,hd);
                 
                 if(mp.find(hd)==mp.end())
                    mp[hd]=curr->data;
                 else
                      mp[hd]+=curr->data;
               
                 if(curr->left) q.push({curr->left,hd-1});
                 if(curr->right) q.push({curr->right,hd+1});
            }
       }
       for(int i=minn;i<=maxx;i++)
        res.push_back(mp[i]);
        return res;
    }
};