class Queue {
public:
    int arr[50000];
    int fr,rear;
       Queue() {
            fr=-1;rear=-1;
         }

    
         bool isEmpty() {
           if(fr==-1) return true;
           return false;
           }

         void enqueue(int data) {
         
                 if((rear+1)%50000 == fr ) return;
                 if(isEmpty())
                     {
                       
                        arr[0]=data;
                        fr=0;rear=0;
                     }
                 else
                     {    
                        rear=(rear+1)%50000;
                        arr[rear]=data;
                     }
                   }

         int dequeue() {
                if(fr== -1) return -1;
                int ans=arr[fr];
                 if(fr==rear)
                    {
                      fr=-1,rear=-1;
                    }
                else
                    fr= (fr+1)%50000;
        
        
                return ans;
            
        
               }

           int front() {
                  if(fr==-1)
                       {
                          return -1;
              
                       }
                 return arr[fr];
    }
};