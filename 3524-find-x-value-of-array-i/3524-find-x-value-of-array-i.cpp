// class Solution {
// public:
//     vector<long long> resultArray(vector<int>& nums, int k) {
//         vector<long long> ans(k, 0);
//         vector<long long> dp(k, 0);

//         for (int x : nums) {
//             vector<long long> newdp(k, 0);

//             // Start a new subarray with just x
//             newdp[x % k]++;

//             // Extend every previous subarray
//             for (int r = 0; r < k; r++) {
//                 int nr = (r * (x % k)) % k;
//                 newdp[nr] += dp[r];
//             }

//             // All subarrays ending here contribute to the answer
//             for (int r = 0; r < k; r++) {
//                 ans[r] += newdp[r];
//             }

//             dp = newdp;
//         }

//         return ans;
//     }
// };



class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<long long>> dp(n, vector<long long>(k, 0));
        vector<long long> ans(k, 0);

        // First element
        dp[0][nums[0] % k] = 1;
        ans[nums[0] % k]++;

        for (int i = 1; i < n; i++) {

            // Start a new subarray [nums[i]]
            dp[i][nums[i] % k]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newR = (r * (nums[i] % k)) % k;
                dp[i][newR] += dp[i - 1][r];
            }

            // Add current subarrays to answer
            for (int r = 0; r < k; r++) {
                ans[r] += dp[i][r];
            }
        }

        return ans;
    }
};