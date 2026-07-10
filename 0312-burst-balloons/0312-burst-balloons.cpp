class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));

        for(int len = 0; len <= n; len++){
            for(int l = 0; l + len < n; l++){
                int r = len + l;

                for(int k = l + 1; k < r; k++){
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + nums[l] * nums[k] * nums[r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};