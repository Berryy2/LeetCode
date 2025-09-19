/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    // Create a dummy node that points to the head.
    // This helps handle edge cases, such as when the head itself needs to be removed.
    struct ListNode dummy;
    dummy.next = head;
    // Two pointers initialized to point at the dummy node.
    // ptr1 will be used to move ahead by n steps first.
    // ptr2 will follow ptr1 to locate the node before the target to delete.
    struct ListNode* ptr1 = &dummy;
    struct ListNode* ptr2 = &dummy;

    // Move ptr1 forward by 'n' steps.
    // After this loop, ptr1 is n nodes ahead of ptr2.
    for(int i = 0; i < n; i++)
    {
        ptr1 = ptr1 -> next; 
    }
    // Now move both ptr1 and ptr2 one step at a time until ptr1 reaches the end.
    // Because ptr1 started n steps ahead, when ptr1 reaches the last node,
    // ptr2 will be exactly one node before the node we want to delete.
    while(ptr1 -> next != NULL)
    {
       ptr1 = ptr1 -> next;
       ptr2 = ptr2 -> next;
    }
    // Now ptr2 -> next is the node we want to remove.
    struct ListNode* delete_node = ptr2 -> next;
    // Skip the target node by linking ptr2 directly to delete_node -> next.
    // This detaches the target node from the list.
    // So, keeps the node-> next pointing to the next node which is not deleted.
    ptr2 -> next = delete_node -> next;
    // Free the memory of the target node to avoid a memory leak.
    free(delete_node);
    // Return the new head (dummy -> next), since the head might have been removed.
    return dummy . next;

}