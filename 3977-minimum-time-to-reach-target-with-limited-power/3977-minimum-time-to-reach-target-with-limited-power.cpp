class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        vector<vector<ll>>dist(n, vector<ll>(power + 1, INF));
        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>>pq;

        dist[source][power] = 0;
        pq.push({0, source, power});

        while(!pq.empty()){
            auto [tim, u, p] = pq.top();
            pq.pop();

            if(tim != dist[u][p]) continue;
            if(p < cost[u]) continue;

            int np = p - cost[u];
            for(auto &[v, w] : adj[u]){
                if(tim + w < dist[v][np]){
                    dist[v][np] = tim + w;
                    pq.push({tim + w, v, np});
                }
            }
        }

        ll bestTime = INF;
        ll bestPow = -1;

        for(ll p = 0; p <= power; p++){
            if(dist[target][p] < bestTime){
                bestTime = dist[target][p];
                bestPow = p;
            }
            else if(dist[target][p] == bestTime){
                bestPow = max(bestPow, p);
            }
        }
        
        if(bestTime == INF){
            return {-1, -1};
        }

        return {bestTime, bestPow};  
    }
};