/* That's a bit manipulation problem:
# We can use a key property of the XOR (^) operation to find the unique element.
#
# XOR properties used:
#   - a ^ a = 0        → same numbers cancel each other out
#   - a ^ 0 = a        → XOR with zero keeps the number
#   - XOR is commutative and associative → order doesn’t matter
#
# Example:
# Input: nums = [2, 2, 1] → Output: 1
#
# Step-by-step:
#   0 ^ 2 = 2
#   2 ^ 2 = 0    (duplicate 2s cancel out)
#   0 ^ 1 = 1    (the single element remains)
#
# Hence, all numbers appearing twice become 0,
# and only the number appearing once is left.
#
# This works for any array where every element appears twice except one*/

int singleNumber(int* nums, int numsSize) 
{
    int StartNum = 0;

    // Loop through all numbers in the list.
    for(int i = 0; i < numsSize;i++)
    {
        // XOR each number with StartNum.
        // Duplicates will cancel out to 0, leaving the single number.
        StartNum ^= nums[i];
    }
    // Return the number that appears only once.    
    return StartNum;
}