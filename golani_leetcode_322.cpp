class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& coins, int amount, int sum, int i) {
        if (sum == amount)
            return 0;

        if (sum > amount || i >= coins.size())
            return INT_MAX / 2;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        if (sum + coins[i] > amount) {
            return dp[i][sum] = solve(coins, amount, sum, i + 1);
        }

        int take = solve(coins, amount, sum + coins[i], i) + 1;
        int nottake = solve(coins, amount, sum, i + 1);

        return dp[i][sum] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());

        int n = coins.size();
        dp.assign(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, amount, 0, 0);

        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};