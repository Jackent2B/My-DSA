#include <bits/stdc++.h>
using namespace std;

//reference:gfg 
int maxProfit(int price[], int n)
{
    int minimumPrice1, minimumPrice2, maxprofit1, maxprofit2;

    minimumPrice1 = minimumPrice2 = INT_MAX;
    maxprofit1 = maxprofit2 = 0;
 
    for (int i = 0; i < n; i++) {
 
        minimumPrice1 = min(minimumPrice1, price[i]);
 
        maxprofit1 = max(maxprofit1, price[i] - minimumPrice1);
 
        minimumPrice2 = min(minimumPrice2, price[i] - maxprofit1);
 
        maxprofit2 = max(maxprofit2, price[i] - minimumPrice2);
    }
    return maxprofit2;
}
 
int main()
{
    int price[] = { 2, 30, 15, 10, 8, 25, 80 };
    int n = sizeof(price) / sizeof(price[0]);
    cout<< maxProfit(price, n);
    return 0;
}