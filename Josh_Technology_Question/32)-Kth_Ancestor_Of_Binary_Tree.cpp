vector<int>final_path;
void helper(BinaryTreeNode<int> *root, int& target,bool & found, vector<int>&curr_path){
    
    if(root==NULL) return;
    if(found) return;
    
    curr_path.push_back(root->data);
    
    if(root->data==target)
    {   final_path=curr_path;
        found=true;
        return;
    }
    
    helper(root->left,target,found,curr_path);
    helper(root->right,target,found,curr_path);
    curr_path.pop_back();
    
}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    vector<int>curr_path;
    bool found=false;
    helper(root,targetNodeVal,found,curr_path);
    
   
    
    int n=final_path.size();
    
    if(k>=n) return -1;
    
    return final_path[n-k-1];
    
}
