// Definition for singly-linked list.
// Each node contains a digit (0-9) and a pointer to the next node.
/* struct ListNode {
     int val;
     struct ListNode *next;
};*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Create a dummy node to simplify edge cases (like empty result).
    // The actual result list will start from dummy->next.
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    
    // 'current' is a moving pointer used to build the result list step by step.
    // It starts at 'dummy' but will move as we add new nodes.
    struct ListNode* current = dummy;

    // 'carry' holds any carry-over when digits add up to >= 10.
    int carry = 0;
    int x = 0, y = 0;  // temporary variables to hold the current digit from each list

    // Loop continues while there are still digits in l1 or l2,
    // OR when there’s a leftover carry (e.g., adding 5+5 = 10 leaves carry 1).
    while (l1 != NULL || l2 != NULL || carry != 0) {
        
        // Extract digit from l1 if available, otherwise use 0.
        if (l1 != NULL) {
            x = l1->val;
        } else {
            x = 0;
        }

        // Extract digit from l2 if available, otherwise use 0.
        if (l2 != NULL) {
            y = l2->val;
        } else {
            y = 0;
        }

        // Compute sum of both digits + carry from previous step.
        int sum = x + y + carry;

        // Update carry for next iteration (integer division by 10).
        carry = sum / 10;

        // Create a new node for the result digit (sum % 10 gives the last digit).
        struct ListNode* result = (struct ListNode*) malloc(sizeof(struct ListNode));
        result->val = sum % 10;
        result->next = NULL;

        // Link the new node to the current result list.
        current->next = result;

        // Move 'current' forward to the newly created node.
        current = current->next;

        // Advance l1 and l2 to the next digits if they are not NULL.
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    // The first node (dummy) was just a placeholder.
    // The actual result list starts from dummy->next.
    return dummy->next;
}
