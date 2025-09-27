/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) 
{
    struct ListNode dummy;
    struct ListNode *prev = &dummy;
    dummy.next = head;
    
    while((prev -> next != NULL) && (prev -> next -> next != NULL))
    {
        struct ListNode *first = prev -> next;
        struct ListNode *second = first -> next;


        struct ListNode *temp = second -> next;
        second -> next = first;
        first -> next = temp; 
        prev -> next = second;

        prev = first;
    }
    return dummy.next;
}