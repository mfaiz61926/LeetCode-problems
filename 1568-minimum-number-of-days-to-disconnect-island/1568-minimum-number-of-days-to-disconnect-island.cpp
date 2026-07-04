class Solution {
public:
    vector<int> adj[1000];
    int tin[1000], low[1000];
    bool vis[1000];
    int timer;
    bool hasArticulation;

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int u, int parent) {
        vis[u] = true;
        tin[u] = low[u] = ++timer;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);

                low[u] = min(low[u], low[v]);

                if (parent != -1 && low[v] >= tin[u])
                    hasArticulation = true;

                children++;
            }
        }

        if (parent == -1 && children > 1)
            hasArticulation = true;
    }

    void dfsComp(int u, vector<bool> &seen) {
        seen[u] = true;
        for (int v : adj[u]) {
            if (!seen[v])
                dfsComp(v, seen);
        }
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Clear graph
        for (int i = 0; i < 1000; i++)
            adj[i].clear();

        int start = -1;
        int land = 0;

        // Build graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;

                land++;
                int node = i * m + j;
                if (start == -1) start = node;

                for (int k = 0; k < 4; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {
                        int adjNode = nr * m + nc;
                        adj[node].push_back(adjNode);
                    }
                }
            }
        }

        if (land == 0)
            return 0;

        // Count connected components
        vector<bool> seen(n * m, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int node = i * m + j;
                    if (!seen[node]) {
                        components++;
                        dfsComp(node, seen);
                    }
                }
            }
        }

        if (components != 1)
            return 0;

        // One land cell is always an articulation in this problem
        if (land == 1)
            return 1;

        memset(vis, false, sizeof(vis));
        memset(tin, 0, sizeof(tin));
        memset(low, 0, sizeof(low));

        timer = 0;
        hasArticulation = false;

        dfs(start, -1);

        return hasArticulation ? 1 : 2;
    }
};