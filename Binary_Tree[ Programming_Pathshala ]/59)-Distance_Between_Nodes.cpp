class Solution {
   public:
    int lca_d,a_d,b_d;
    Node* lowestCommonAncestor(Node* root, int a,int b) {
        if(root==NULL) return NULL;
        
        if(root->data== a || root->data==b) return root;
        
        Node* lft=lowestCommonAncestor(root->left,a,b);
        Node* rgt=lowestCommonAncestor(root->right,a,b);
        
        if(lft && rgt) return root;
        if(lft==nullptr) return rgt;
        return lft;
        
    }
    void findD(Node* root,Node* lca,int a,int b,int height)
    {
        if(root==NULL) return;
        if(root->data==a) a_d=height;
        if(root->data==b) b_d=height;
        if(root->data==lca->data) lca_d=height;
        findD(root->left,lca,a,b,height+1);
        findD(root->right,lca,a,b,height+1);
       
    }

    int findDist(Node* root, int a, int b) {
        
        Node* lca=lowestCommonAncestor(root,a,b);
        findD(root,lca,a,b,0);
        return a_d+b_d-2*lca_d;
       
    }
};
