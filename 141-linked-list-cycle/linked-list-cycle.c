/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
    struct ListNode *FastPtr = head;
    struct ListNode *SlowPtr = head;
    
    while (FastPtr != NULL && FastPtr->next != NULL)
    {
        FastPtr = FastPtr -> next -> next;  
        SlowPtr = SlowPtr -> next;
        if(FastPtr == SlowPtr)
        {
            return true;
        }  
    }
    return false;
}