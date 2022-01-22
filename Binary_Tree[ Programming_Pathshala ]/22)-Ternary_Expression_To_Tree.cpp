Node *convertExpression(string str,int i)
{
   if(i>=str.length())  return NULL;
     
    Node* newnode= new Node(str[i]);
    
    if(i+1<str.length() && str[i]=='?') newnode->left=convertExpression(str,i+2);
    else  newnode->right=convertExpression(str,i+2);
      
    return newnode;     
}