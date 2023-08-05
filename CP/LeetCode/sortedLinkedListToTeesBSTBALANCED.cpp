TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return new TreeNode(head->val);
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *previousSlow = NULL;
        while (fast != NULL && fast->next != NULL) {
            previousSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        previousSlow->next = NULL;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }