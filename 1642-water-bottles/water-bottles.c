// Here you can see my O(log(n)) answer and there is an O(1) geometric form;
int numWaterBottles(int numBottles, int numExchange) 
{
    // Total keeps track of how many bottles have been drunk.
    int total = numBottles;
    // Continue as long as we have enough empty bottles to exchange.
    while (numBottles >= numExchange)
    {
    // How many new full bottles we get by exchanging.
    // using that we by default take the floor of this division.
    int ChangedBottles = numBottles / numExchange;
    // Update the current bottle count:
    //   - the newly obtained full bottles (changed)
    //   - plus the leftover empties that weren’t enough to exchange.
    numBottles = ChangedBottles + (numBottles % numExchange);
    // Add the new full bottles to the total drunk count.
    total += ChangedBottles;
    }
    // Return the maximum number of bottles that can be drunk.
    return total;
}