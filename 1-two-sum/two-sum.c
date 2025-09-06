/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // First Answer -> the first Idea will come to new members in leetcode.
 // which by the way better for the memory but bad for time complexty
/*//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for(int i = 0 ; i< numsSize; i++ )
    {
        for(int j = 1 ; j< numsSize ; j++ )
        {
            if ((i != j) && (nums[i] + nums[j] == target))
            {
                int* result = (int*)malloc(2 * sizeof(int)); 
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}*/
//solving for linear time complexity using hashTable approach.
//#include "uthash.h" //Library used to take the HashTable approach in C
// making our hash table 
typedef struct{
    int index; // For index which we will return 
    int key;  // For the index's value
    UT_hash_handle hh; //the name of the handle in the struct
}ht;
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
ht *table = NULL; // Pointer points to the head of the hashtabel 
ht *entry = NULL; // pointer to be used for Operations like Hash Add/Find
for(int i = 0; i < numsSize; i++)
{
int compliment = target - nums[i]; // Store the comp. value so, if we found 
                                // it in the table we then got our value
HASH_FIND_INT(table, &compliment, entry);
if(entry) //if we found the compliment in the table.
{
    int *res = malloc(2* sizeof(int));
    res[0] = entry -> index;
    res[1] = i;
    *returnSize = 2; //needed from the problem.
    //Then we free our table to clear the memory.
    ht *current, *temp; //If we delete cur during iteration, you’d lose track 
                        //of the next element. HASH_ITER stores it in tmp so 
                        //iteration is safE.
    HASH_ITER(hh, table, current, temp)
    {
        HASH_DEL(table, current);
        free(current);
    } //You can also use HASH_CLEAR directly
    return res; 
}
    entry = malloc(sizeof(ht));
    entry -> key = nums[i]; // Storing value in the i's index,
    entry -> index = i;    // Storing the index itself.
    HASH_ADD_INT(table, key, entry);
    }
    *returnSize = 0;
    ht *current, *temp;
    HASH_ITER(hh, table, current, temp)
    {
        HASH_DEL(table, current);
        free(current);
    }
    return NULL;
}