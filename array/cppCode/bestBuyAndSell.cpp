#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int maximumProfit = 0;
    int bestBuy = prices[0];
    int n = prices.size();

    for(int i = 1; i < n; i++) {
        if(prices[i] > bestBuy) {
            maximumProfit = max(maximumProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maximumProfit;
}

int main() {
    vector<int> prices = {7, 5, 2, 6, 1, 4};
    int ans = maxProfit(prices);
    cout << ans << endl;

    return 0;
}