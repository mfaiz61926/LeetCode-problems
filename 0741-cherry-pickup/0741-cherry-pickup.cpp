class Solution {
public:
    int dp[51][51][51];
    int n;
    int solve(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;

        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = grid[r1][c1];
        if (r1 != r2 || c1 != c2) cherries += grid[r2][c2];

        int ans = cherries + max({
            solve(grid, r1 + 1, c1, r2 + 1), // down, down
            solve(grid, r1 + 1, c1, r2),     // down, right
            solve(grid, r1, c1 + 1, r2 + 1), // right, down
            solve(grid, r1, c1 + 1, r2)      // right, right
        });

        return dp[r1][c1][r2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        return max(0, solve(grid, 0, 0, 0));
    }
};