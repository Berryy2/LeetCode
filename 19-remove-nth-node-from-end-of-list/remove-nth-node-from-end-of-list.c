/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* ptr1 = &dummy;
    struct ListNode* ptr2 = &dummy;

    for(int i = 0; i < n; i++)
    {
        ptr1 = ptr1 -> next; 
    }
    while(ptr1 -> next != NULL)
    {
       ptr1 = ptr1 -> next;
       ptr2 = ptr2 -> next;
    }
    struct ListNode* delete_node = ptr2 -> next;
    ptr2 -> next = delete_node -> next;
    free(delete_node);
    return dummy.next;

}