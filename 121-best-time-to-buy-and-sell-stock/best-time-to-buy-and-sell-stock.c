int maxProfit(int* prices, int pricesSize) 
{
    int profit = 0;
    int min = INT_MAX;
    for (int i = 0; i < pricesSize; i++)
    {
        if(prices[i] < min)
        {
            min = prices[i];
        }

        if(prices[i] - min > profit)
        {
            profit = prices[i] - min;
        }
    }
    return profit;
}