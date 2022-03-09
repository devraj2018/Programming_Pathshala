BinaryTreeNode<char> * helper(string &str,int &curr_I){

     if(curr_I>=str.length()) return NULL;
    
     BinaryTreeNode<char> * root=new BinaryTreeNode<char>(str[curr_I]);
      curr_I++;
     if(curr_I<str.size() && str[curr_I]=='?')
        {  curr_I++;
           root->left=helper(str,curr_I);
         
           curr_I++;
          root->right=helper(str,curr_I);
         
         }
    return root;
  
}
 
BinaryTreeNode<char> * toBinaryTree(string &str){
    int curr_I=0;
    
    return helper(str,curr_I);
}
