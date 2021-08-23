    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* temp=head;int n=0;
        ListNode* prev=NULL;
        while(temp!=NULL){
            n++;
            prev=temp;
            temp=temp->next;
            
        }
        k=k%n;
        if(k==0) return head;
        prev->next=head;
        int x=n-k;
        while(x--){
            head=head->next;
            prev=prev->next;
        }
        prev->next=NULL;
        
        
        
        return head;
    }
