class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int>res;
            int i=0,j=0,k=0;
            
            while(i<n1 && j<n2 && k<n3)
            {    if( (A[i] == B[j]) && (A[i]==C[k]))
                     {
                       res.push_back(A[i]);
                       while(i<n1 && A[i]==B[j]) i++;
                       j++;k++;
                    }
                    
                    else if(A[i]< B[j] || A[i]<C[k]) i++;
                    else if(B[j]< C[k] || B[j]<A[i]) j++;
                    else if(C[k]< B[j] || C[k]<A[i]) k++;
           }
            return res;
        }

};