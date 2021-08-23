    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        ListNode* head1 = list1,*head2 = list2 , *slow = head1 , *fast = head1;
        
        for(int i=1 ; i<a ; i++)
            slow = slow->next;
        
        for(int i=0 ; i<b ; i++)
            fast = fast->next;
        
        slow->next = head2;
        
        while(head2->next !=NULL)
            head2 = head2->next;
        
        head2->next = fast->next;
        
        return head1;
    }