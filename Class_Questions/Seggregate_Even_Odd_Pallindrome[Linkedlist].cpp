#include <iostream>
using namespace std;
class node{
	  public:
	     int val; node* next;
	   node(int x) {  val=x; next=NULL; }
};
bool isPall(int n)
{   int sum=0,r,temp;    
     temp=n;    
    while(n>0)    
     {    
       r=n%10;
       sum=sum*10 +r;
       n=n/10;
     }    
   if(temp==sum) return true;   
   return false;  

}
node* helper(node* head)
{   if(head==NULL) return NULL;

    node* even=new node(0);
    node* odd=new node(0);
    node* pal=new node(0);
    node* even_tail=even,*odd_tail=odd,*pal_tail=pal;
	
	while(head)
	{
		 if(isPall(head->val))
		 {
		 	pal_tail->next=head;
		 	head=head->next;
		 	pal_tail=pal_tail->next;
		 	pal_tail->next=NULL;
		 }
		 else if(head->val%2==0)
		 {
		 	
		 	even_tail->next=head;
		 	head=head->next;
		 	even_tail=even_tail->next;
		 	even_tail->next=NULL;
		 
		 }
		 else
		 {
		 	odd_tail->next=head;
		 	head=head->next;
		 	odd_tail=odd_tail->next;
		 	odd_tail->next=NULL;
		 }
		
	}
	
	even_tail->next=odd->next;
	odd_tail->next=pal->next;
    return even->next;
	
}
int main() {

   node* head=new node(1);
   head->next=new node(2);
   head->next->next=new node(121);
   head->next->next->next=new node(12);
   head->next->next->next->next=new node(21);
   node* temp=head;
   cout<<"Before Any Operation LL look likes ";
    while(temp)
   {
   	cout<<temp->val<<" ";
   	temp=temp->next;
   }
   cout<<endl;
   node * newhead=helper(head);

    cout<<"After function Call LL look likes ";
   while(newhead)
    {
   	cout<<newhead->val<<" ";
   	newhead=newhead->next;
 } 
   
}