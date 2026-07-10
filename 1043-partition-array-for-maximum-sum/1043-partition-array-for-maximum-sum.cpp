class Solution {
public:
    // int dp[501];
    // int f(int i, vector<int>&arr, int n, int k){
    //     if(i == n) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int mx = INT_MIN;
    //     int len = 0;
    //     int ans = INT_MIN;

    //     for(int j = i; j < min(n, i + k); j++){
    //         mx = max(mx, arr[j]);
    //         len++;
    //         ans = max(ans, len * mx + f(j + 1, arr, n, k));
    //     }
    //     return dp[i] = ans;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // memset(dp, -1, sizeof(dp));
        // return f(0, arr, n, k);
        vector<int>dp(n + 1, 0);
        
        for(int i = n - 1; i >= 0; i--){
            int len = 0;
            int mx = INT_MIN;
            int ans = INT_MIN;
            for(int j = i; j < min(n, i + k); j++){
                len++;
                mx = max(mx, arr[j]);
                ans = max(ans, len * mx + dp[j + 1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};