class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n, 0);

        for(int i = 0; i < n; i++){
            int len = 0;
            int mx = INT_MIN;
            int ans = INT_MIN;
            for(int j = i; j >= max(0, i - k + 1) ; j--){
                len++;
                mx = max(mx, arr[j]);
                ans = max(ans, len * mx + (j - 1 >= 0 ? dp[j - 1] : 0));
            }
            dp[i] = ans;
        }
        return dp[n - 1];
    }
};