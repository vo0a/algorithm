class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int size = matrix.size();
        int sizeJ = matrix[0].size();

        vector<vector<int>> dp(size, vector<int>(sizeJ));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < sizeJ; j++) {
                if (i - 1 < 0 || j - 1 < 0) {
                    dp[i][j] = matrix[i][j];
                    ans += matrix[i][j];
                    continue;
                }
                if (matrix[i][j])
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                else dp[i][j] = 0;
                ans += dp[i][j];
            }
        }
        return ans;
    }
};