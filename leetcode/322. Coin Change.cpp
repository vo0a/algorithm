class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());

        vector<int> dp(amount + 1, 1e9);
        int n = coins.size();
        for (int i = 0; i < n; i++) {
            int coin = coins[i];		
            if (coin > amount) break;

            dp[coin] = 1;
            for (int j = coin; j <= amount; j++) {
                dp[j] = min(dp[j], dp[coin] + dp[j - coin]);
            }
        }

        if (amount < coins[0]) return -1;
        else if (dp[amount] == 1e9) return -1;
        return dp[amount];
    }
};