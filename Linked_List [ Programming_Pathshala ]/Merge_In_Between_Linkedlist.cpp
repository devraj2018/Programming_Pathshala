class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy=new ListNode(0);
        dummy->next=list1;
        
        ListNode* prev_of_a=dummy,*prev_of_b=dummy,*temp=list1;
        int i=0;
        ListNode *a_th_node,*b_th_node;
        ListNode* last=list2;
        while(last->next) last=last->next;
        while(i<a)
        {   prev_of_a=temp;
            prev_of_b=temp;
            temp=temp->next;
            a_th_node=temp;b_th_node=temp;
            i++;
        }
        
        while(i<b)
        {
           prev_of_b=temp;
           temp=temp->next;
           b_th_node=temp;
           i++;
        }
        
        if(prev_of_a==prev_of_b)    //When only one node is to deleted
        {   last->next=a_th_node->next;
            prev_of_a->next=list2;
            return dummy->next;
            
        }
        last->next=b_th_node->next;   //When range of node is to deleted
        prev_of_a->next=list2;
        return dummy->next;
           
    }
};