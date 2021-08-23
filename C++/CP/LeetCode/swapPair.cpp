// 
ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        ListNode* tail = swapPairs(head->next->next);
        
        ListNode* new_head = head->next;
        head->next = tail;
        new_head->next = head;
        
        return new_head;
    }
    // My solution
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp = head,*ptr = head;
        if(head && head->next){
        head = head->next;
        temp->next = head->next;
        head->next = temp ;
        }   
        while(temp && temp->next && (temp->next)->next ){
            ptr = temp->next;
            temp->next = ptr->next;
            ptr->next = (temp->next)->next;
            (temp->next)->next = ptr;
            temp = ptr;
        }
        return head;
    }