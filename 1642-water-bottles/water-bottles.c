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
/*
"Simply and shortly each time you exchange X empty bottles (-X) you get on full which
you will drink to be empty -> (-X + 1) = -(X - 1).
the key is to know how many time you can exchange (Y)
for ex: you have 9 bottles and exchange  = 3.
according to what we say the every trade cost you 2 bottles -(3 - 1)
How many “2’s” can you subtract until you’re left with fewer than 3?
9 → 7 → 5 → 3 → 1. That’s 4 exchanges.
Formula: (9 – 1)/(3 – 1) = 8/2 = 4. Matches.
and why 9 (- 1) because the last empty bottles will not be exchanged at the end 
so it's useless to count it.""

int numWaterBottles(int numBottles, int numExchange) {
    // problem guarantees numExchange >= 2
    return numBottles + (numBottles - 1) / (numExchange - 1);
}
*/