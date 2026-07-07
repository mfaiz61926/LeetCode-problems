class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m + 1, vector<int>(m + 1, 0));

        for(int len = 0; len <= m; len++){
            for(int l = 0; l + len < m; l++){
                int r = l + len;

                dp[l][r] = 1e9;
                for(int k = l; k <= r; k++){
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + cuts[r] - cuts[l]);
                }
                if(dp[l][r] == 1e9) dp[l][r] = 0;
            }
        }
        return dp[0][m - 1];
    }
};