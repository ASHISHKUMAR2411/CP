    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode *prev = head;
        int data = -101 ;
        while(head && head->next &&( head->val == (head->next)->val || head->val == data )){
            prev = head;
            data = head->val;
            head = (head->next);
        }
        if(head->val == data) head = head->next;
        ListNode* curr = head;
        int count = 0 ;
        while(curr)
        {
            count = 0;
            while(curr && curr->next && (curr->val == (curr->next)->val || curr->val == data)){
                data = curr->val;
                prev->next = (curr->next);
                curr = curr->next;
                 count = 1;
            }
            if( curr && prev->next  && (data == curr->val)) prev->next = curr->next;
            if(count==0){
                prev = curr;
                curr = curr->next;
            }
            else ;
        }
        
        return head;
    }
};