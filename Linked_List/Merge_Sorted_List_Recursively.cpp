class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        ListNode* newhead;
        if(list1->val<=list2->val)
           { newhead=list1;
             list1=list1->next;
           }
        else
            { newhead=list2;
              list2=list2->next;
             }
        newhead->next=mergeTwoLists(list1,list2);
        return newhead;
            
    }
};