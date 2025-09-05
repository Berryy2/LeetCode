int maxProfit(int* prices, int pricesSize) {
    int max = 0;
    int L = 0;
    //Using Sliding Window Pattern
    for(int R = 1; R < pricesSize; R++)
    {
        int profit = prices[R] - prices[L];
        if(profit > max)
        {
            max = profit;
        }
        if (profit < 0)
        {
            L = R;
        }
    }
    return max;
}