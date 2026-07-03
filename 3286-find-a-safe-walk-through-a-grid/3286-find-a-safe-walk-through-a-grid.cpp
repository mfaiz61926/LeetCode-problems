class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        priority_queue<tuple<int,int,int>>pq;
        vector<vector<int>>bestH(n, vector<int>(m, -1));

        int start = health - grid[0][0];
        if(start <= 0) return false;

        pq.push({start, 0, 0});
        bestH[0][0] = start;

        while(!pq.empty()){
            auto [h, r, c] = pq.top();
            pq.pop();

            if(h < bestH[r][c]) continue;
            if(r == n - 1 && c == m - 1) return true;

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int nh = h - grid[nr][nc];
                if(nh <= 0) continue;

                if(nh > bestH[nr][nc]){
                    bestH[nr][nc] = nh;
                    pq.push({nh, nr, nc});
                }
            }
        }
        return false;
    }
};