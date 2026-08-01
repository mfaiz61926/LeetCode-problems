class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int f(int i , int j, vector<int>&a){
        if(i == j) return a[i];

        //p1 takes left
        if(dp[i][j] != INT_MIN) return dp[i][j];

        int left = a[i] - f(i + 1, j, a);
        int right = a[j] - f(i, j - 1, a);

        return dp[i][j] = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        // memset(dp, INT_MIN, sizeof(dp));
        dp.assign(n, vector<int>(n, INT_MIN));
        return f(0, n - 1, nums) >= 0;
    }
};