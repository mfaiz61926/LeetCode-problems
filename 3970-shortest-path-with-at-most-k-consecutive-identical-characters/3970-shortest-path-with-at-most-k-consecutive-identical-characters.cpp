class Solution {
public:
    vector<pair<int,int>>adj[50005];
    const int INF = 1e9;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>pq;
        pq.push({0, 0, 1});
        vector<vector<int>>dist(n, vector<int>(k + 1, INF));
        dist[0][1] = 0;

        while(!pq.empty()){
            auto [dis, u, cnt] = pq.top();
            pq.pop();

            if(dis != dist[u][cnt]) continue;
            if(cnt > k) continue;

            for(auto &[v, w] : adj[u]){
                int x;
                if(labels[u] == labels[v]) x = cnt + 1;
                else x = 1;
                if(x > k) continue;
                if(dis + w < dist[v][x]){
                    dist[v][x] = dis + w;
                    pq.push({dist[v][x], v, x});
                }
            }
        }
        int ans = INF;
        for(int c = 1; c <= k; c++){
            ans = min(ans, dist[n - 1][c]);
        }

        return ans == INF ? -1 : ans;
    }
};