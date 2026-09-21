class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> newdp(k, 0);

            // Start a new subarray with just x
            newdp[x % k]++;

            // Extend every previous subarray
            for (int r = 0; r < k; r++) {
                int nr = (r * (x % k)) % k;
                newdp[nr] += dp[r];
            }

            // All subarrays ending here contribute to the answer
            for (int r = 0; r < k; r++) {
                ans[r] += newdp[r];
            }

            dp = newdp;
        }

        return ans;
    }
};