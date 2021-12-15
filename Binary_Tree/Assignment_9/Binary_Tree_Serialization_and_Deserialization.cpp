void serialize(Node *root,vector<int> &A)
{   if(root==NULL)
    {A.push_back(-1);
      return;
     }
    A.push_back(root->data);
    serialize(root->left,A);
    serialize(root->right,A);
}

 
 Node * de(vector<int>&A,int &index)
 {
    if(index==A.size())
    return NULL;
    int val=A[index];
    index++;
    if(val==-1)
    return NULL;
    Node*temp=new Node(val);
    temp->left=de(A,index);
    temp->right=de(A,index);
    return temp;
 }
Node * deSerialize(vector<int> &A)
{   int index=0;
    return de(A,index);
   
}
