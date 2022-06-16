/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void serHelper(TreeNode<int> *root,string &res)
{
     if(root==NULL)
     {
         res+="#";
         return;
     }
    
    res+=to_string(root->data);
    res+="X";
    
    serHelper(root->left,res);
    serHelper(root->right,res);
   
}
string serializeTree(TreeNode<int> *root)
{
   string res="";
   serHelper(root,res);
   return res;
}

TreeNode<int>* deHelper(string &s,int &curr_I)
{
     if(curr_I>=s.length()) return NULL;
    
     if(s[curr_I]=='#')
     {
         curr_I++;
         return NULL;
     }
    
     string temp="";
     while(curr_I<s.length() && s[curr_I]!='X')
     {
         temp+=s[curr_I];
         curr_I++;
     }
     curr_I++;
    
     TreeNode<int>* root= new TreeNode<int>(stoi(temp));
     root->left=deHelper(s,curr_I);
     root->right=deHelper(s,curr_I);
    return root;
    
    
      
}
TreeNode<int>* deserializeTree(string &s)
{
   int curr_I=0;
   return deHelper(s,curr_I);
}



