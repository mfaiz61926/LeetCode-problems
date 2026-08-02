class Solution {
public:
    int dp[501][501];
    int f(int i, int j, int sum, vector<int>&piles){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = piles[i] - f(i + 1, j, sum, piles);
        int right = piles[j] - f(i, j - 1, sum, piles);
        return dp[i][j] = max(left, right);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // memset(dp, -1, sizeof(dp));
        // return f(0, n - 1, 0, piles) >= 0;
        for(int i = 0; i < n; i++) dp[i][i] = piles[i];
        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;

                int left = piles[i] - dp[i + 1][j];
                int right = piles[j] - dp[i][j - 1];

                dp[i][j] = max(left, right);
            }
        }

        return dp[0][n - 1];
    }
};