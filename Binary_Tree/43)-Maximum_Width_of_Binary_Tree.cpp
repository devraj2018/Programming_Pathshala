int getMaxWidth(Node* root) {

        if(root==NULL) return 0;
        queue<Node*>q;
        q.push(root);
        int maxx=INT_MIN;
         while(!q.empty())
           {   
            int size=q.size();
            maxx=max(maxx,size);
            for(int i=0;i<size;i++)
            {
                 
                Node* curr=q.front();
                q.pop();
                if(curr->left)q.push({curr->left,width-1});
                if(curr->right)q.push({curr->right,width+1});
            }
          }
        return maxx;
        
 
    }