int getDecimalValue(ListNode* head) {
        auto temp=head;
        int ans=0;
        while(temp){
            ans=ans*2+temp->val;
            temp=temp->next;
        }
        return ans;
}