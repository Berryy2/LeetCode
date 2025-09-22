/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
{
    // We will start by making dummy node with a pointer (temp) which will build our 
    // resulted merged list step by step.
    // Also dummy node simplify edge cases.
    struct ListNode dummy;
    struct ListNode* temp = &dummy;
    
    // We will loop in two linked list tell until one of them (&&) reaches its end.
    while((list1 != NULL) && (list2 != NULL))
    {
        // Classic condition if the node in list value's is smaller or equal than the other
        //  we will make the resulted list's pointer's next value be it.
        if((list1 -> val) <= (list2 -> val))
        {
            temp -> next = list1;
            // Increment in the List.
            list1 = list1 -> next;
        }
        // Same if the other list's value is smaller.
        else
        {
            temp -> next = list2;
            // Increment in the List.
            list2 = list2 -> next;
        }
        // Move 'temp' forward to the newly added node,
        // so the next insertion happens at the correct place.
        temp = temp -> next;
    }
    // When one of the nodes reaches its end point (NULL).
    // Directly attach the remaining nodes from the non-empty list.
    if(list1 != NULL) temp->next = list1;
    if(list2 != NULL) temp->next = list2;

    // At the end as the problem say we return the head of the merged list.
    // skipping the dummy head.
    return dummy.next;
}