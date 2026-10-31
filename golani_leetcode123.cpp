#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int solve(vector<int>& prices, int i, int t, int buy,
              vector<vector<vector<int>>>& dp) {
        if (i >= prices.size() || t >= 2) {
            return 0;
        }

        if (dp[i][t][buy] != -1) {
            return dp[i][t][buy];
        }

        if (buy == 1) {
            int pass = solve(prices, i + 1, t, buy, dp);
            int sell = solve(prices, i + 1, t + 1, 0, dp) + prices[i];
            return dp[i][t][buy] = max(pass, sell);
        } else {
            int b = solve(prices, i + 1, t, 1, dp) - prices[i];
            int pass = solve(prices, i + 1, t, buy, dp);
            return dp[i][t][buy] = max(b, pass);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(3, vector<int>(2, -1)));

        int ans = solve(prices, 0, 0, 0, dp);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
