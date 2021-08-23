    // time less
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        if(h1==NULL){
            return h2;
        }
        if(h2==NULL){
            return h1;
        }
        ListNode* ans=NULL;
        ListNode* curr;
        bool pos=0;
        while(h1 && h2){
            if(h1->val<h2->val){
                if(ans==NULL){
                    ans=h1;
                }
                if(pos==0){
                    curr=h1;
                    h1=h1->next;
                }else{
                    curr->next=h1;
                    curr=h1;
                    h1=h1->next;
                    pos=0;
                }
            }else if(h1->val>h2->val){
                if(ans==NULL){
                    ans=h2;
                    pos=1;
                }
                if(pos==0){
                    curr->next=h2;
                    curr=h2;
                    h2=h2->next;
                    pos=1;   
                }else{
                    curr=h2;
                    h2=h2->next;
                    
                }
            }else{
                if(ans==NULL){
                    ans=h1;
                }
                if(pos==0){
                    curr=h1;
                    h1=h1->next;
                    curr->next=h2;
                    curr=h2;
                    h2=h2->next;
                    pos=1;
                }else{
                    curr=h2;
                    h2=h2->next;
                }
            }
                if(h1==NULL){
                    curr->next=h2;
                }
                if(h2==NULL){
                    curr->next=h1;
                } 
        }
        
         return ans;
    }
    // time less
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }



    // space less 
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* temp,*head;
        if(l1->val<=l2->val)
        {
            temp=l1;
            l1=l1->next;
        }
        else
        {
            temp=l2;
            l2=l2->next;
        }
        
        head=temp;
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                temp->next=l1;
                temp=l1;
                l1=l1->next;
            }
            else
            {
                temp->next=l2;
                temp=l2;
                l2=l2->next;
            }
            
        }
        if(l1!=NULL)
        {
            temp->next=l1;
        }
        else
            temp->next=l2;
            
        
        return head;
    }



    // merge k lists together
    
void merge(int left, int right, vector<ListNode*>& arr){
    int mid=(left+right)/2;
    ListNode* head1=arr[left];
    ListNode* head2=arr[mid+1];
    if(!head1)
        arr[left]=head2;
    else if(!head2)
        arr[left]=head1;
    else if(head1&&head2){
        if(head1->val>head2->val)
            swap(head1, head2);
        arr[left]=head1;
        ListNode* pre=head1;
        head1=head1->next;
        while(head1&&head2){
            if(head1->val<=head2->val){
                pre=head1;
                head1=head1->next;
            }
            else{
                pre->next=head2;
                head2=head2->next;
                pre->next->next=head1;
                pre=pre->next;
            }
        }
        if(head2)
            pre->next=head2;
    }
}


void divide(int left, int right, vector<ListNode*>& arr){
    if(left<right){
        int mid=(left+right)/2;
        divide(left, mid,arr);
        divide(mid+1, right,arr);
        merge(left, right, arr);
    }
}




class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
            return NULL;
       divide(0,lists.size()-1,lists);
        return lists[0];
    }
};