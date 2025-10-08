// In this approach, we use the "Boyer–Moore Majority Voting Algorithm".
// The main idea is to find a "candidate" element that could be the majority element.
// We maintain a vote counter that increases when we see the same candidate,
// and decreases when we see a different number. 
// When the vote count drops to zero, we switch to a new candidate.
// The element that survives with a positive vote at the end is the potential majority element.
int majorityElement(int* nums, int numsSize) 
{
    // We initialize candidate & vote by zeros.
    int candidate = 0;
    int vote = 0;
    // We loop in the array to find the potential majority candidate.
    for(int i = 0; i < numsSize; i++)
    {
        // When the vote = 0 or when we start we make the current element in the loop which
        // decremented the vote to zero as the new candidate.(or the first element).
        if(vote == 0)
        {
            // Current array element will be our new candidate.
            candidate = nums[i];
            // And start its vote count at 1. 
            vote++;
        }
        else
        {
            // If the current element equals the candidate, increment vote.
            if(nums[i] == candidate)
                vote++;
            else 
                // Otherwise, decrement vote.
                vote--;
        }
        // We shall leave the for loop with candidate variable have the value of the element
        // with most votes (the major element).
    }
        // After the loop, 'candidate' is the potential majority element.
        // But we still need to verify it actually appears more than n/2 times.
        int count = 0;
        for(int i = 0; i < numsSize; i++)
        {
            if(nums[i] == candidate)
            count++;
        }
        // Then we check the problmes goal which is that element should appear in more than
        // half of the array.
        if(count > (numsSize / 2))
            // If it fits the goal, we return that candidate.
            return candidate;
        // Valid majority element found.
        return -1;
}