int numWaterBottles(int numBottles, int numExchange) 
{
    int total = numBottles;
    while (numBottles >= numExchange)
    {
    int NotChangedBottles = numBottles / numExchange;
    numBottles = NotChangedBottles + (numBottles % numExchange);
    total += NotChangedBottles;
    }
    return total;
}