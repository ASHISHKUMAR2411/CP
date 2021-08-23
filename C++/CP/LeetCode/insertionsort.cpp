ListNode* insertionSortList(ListNode* head) {
        vector<int> rec;
        int idx = 0;
        ListNode* tmp = head;
        while(tmp) {
            rec.push_back(tmp->val);
            tmp = tmp->next;
        }
        sort(rec.begin(),rec.end());
        tmp = head;
        while(tmp) {
            tmp->val = rec[idx];
            tmp = tmp->next;
            ++idx;
        }
        return head;
    }

    ListNode* insertionSortList(ListNode* head) {
        if (head->next == nullptr)
            return head;
        ListNode* iter = head;
        ListNode* left;
        int curr = iter->val;
        ListNode* temp{nullptr};
        do{
            ListNode* prev = iter;
            iter = iter->next;
            if (iter->val >= curr){
                curr = iter->val;
            }
            else{
                prev->next = iter->next;
                temp = head;
                while (iter->val > temp->val){
                    left = temp;
                    temp = temp->next;
                }
                if (temp != head){
                    left->next = iter;
                    iter->next = temp;
                }
                else{
                    head = iter;
                    iter->next = temp;
                }
                iter = prev;
            }
        } while (iter->next != nullptr);
        return head;
    }

 ListNode* insertionSortList(ListNode* head) {
        if(!head || head->next==NULL) return head;
        ListNode* temp, *curr = head->next, *prev, *node;
        head->next = NULL;
        
        while(curr){
            node = curr;
            curr = curr->next;
            temp = head;
            while(temp && temp->val < node->val){
                prev = temp;
                temp = temp->next;
            }
            if(temp==head){
                node->next = temp;
                head = node;
            }else{
                prev->next = node;
                node->next = temp;
            }
        }
        return head;
    }