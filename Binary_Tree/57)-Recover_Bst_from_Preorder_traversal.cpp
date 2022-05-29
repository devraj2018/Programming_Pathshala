 
class Solution {
public:
    TreeNode* helper(string s,int curr_depth,int &curr_I)
    {    if(curr_I>= s.length()) return NULL;
         int count=0;             // to count dashes so we can find that currlevel is correct or not for this node 
         int t=curr_I;            //store in t,bcz if thats not valid node for curr_depth ,we have to backtrack our curr_I
         while( s[t]=='-')
         {   count++;
             t++;
         }
         if(count<curr_depth)  return NULL;     
         curr_I=t;          
         string temp="";
         while(curr_I<s.length() && s[curr_I]!='-')
         {   temp.push_back(s[curr_I]);
             curr_I++;
         }
         
          int val=stoi(temp);
          TreeNode* root=new  TreeNode(val);
            
          root->left=helper(s,curr_depth+1,curr_I);
          root->right=helper(s,curr_depth+1,curr_I);
          return root;
     }
     
    TreeNode* recoverFromPreorder(string s) {
        if(s.length()==0) return NULL;
        int curr_depth=0;
        int curr_I=0;
        return helper(s,curr_depth,curr_I);
        
    }
};