ListNode* reverseList(ListNode* head) {
             ListNode *curr=head, *prev = nullptr;
        
        while( curr ){
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        return prev;

}
if(head==NULL||head->next==NULL){
            return head;
        ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
}