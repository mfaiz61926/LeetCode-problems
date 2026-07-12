class Solution {
public:
    int dp[72][72][72];
    int n, m;
    vector<vector<int>>g;
    int dfs(int r, int c1, int c2){
        if(r == n - 1){
            if(c1 == c2) return g[r][c1];
            else return g[r][c1] + g[r][c2];
        }

        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int ans = 0;
        if(c1 == c2) ans += g[r][c1];
        else ans += g[r][c1] + g[r][c2];

        int best = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int nc1 = c1 + i;
                int nc2 = c2 + j;

                if(nc1 < 0 || nc1 >= m || nc2 < 0 || nc2 >= m) continue;
                best = max(best, dfs(r + 1, nc1, nc2));
            }
        }

        return dp[r][c1][c2] = ans + best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        g = grid;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, m - 1);
    }
};