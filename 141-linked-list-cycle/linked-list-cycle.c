
/* Our approach for this problem Cycle Detection Algorithm (also known as Tortoise and Hare algorithm).
* The idea is to use two pointers moving at different speeds:
* SlowPtr moves one step at a time.
* FastPtr moves two steps at a time.
* If there’s a cycle, these two pointers will eventually meet at the same node.
* If FastPtr reaches NULL, that means the list has an end → no cycle exists.
* Time Complexity:  O(n) ->  each node is visited at most twice.
* Space Complexity: O(1) ->  we only use two pointers.
*******************************************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool hasCycle(struct ListNode *head) 
{
    // Initialize two pointers, both starting at the head.
    struct ListNode *FastPtr = head;
    struct ListNode *SlowPtr = head;

    // Continue looping while the fast pointer and its next are not NULL.
    // If fast reaches the end, there is no cycle.
    while (FastPtr != NULL && FastPtr->next != NULL)
    {
        // Move the fast pointer by two steps at a time.
        FastPtr = FastPtr -> next -> next;  
        // Move the slow pointer by one step at a time.
        SlowPtr = SlowPtr -> next;

        // If both pointers meet, a cycle exists.
        if(FastPtr == SlowPtr)
        {
            return true;
        }  
    }

    // If we exit the loop, it means the list ended so, no cycle found.
    return false;
}