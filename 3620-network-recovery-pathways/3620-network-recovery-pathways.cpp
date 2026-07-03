class Solution {
public:
    using ll = long long;
    vector<pair<int,int>>adj[50005];
    int mxNode = 0;
    const ll INF = 1e18;

    bool check (ll mid, ll k, vector<bool>&online){
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>>pq;
        pq.push({0, 0});
        vector<ll>dist(mxNode + 1, INF);
        dist[0] = 0;

        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();
            if(dis != dist[node]) continue; // u can use >
            if(online[node] == false) continue;

            if(node == mxNode && dis <= k) return true;

            for(auto &[v, w] : adj[node]){
                if(w < mid) continue;
                if(dis + w < dist[v]){
                    dist[v] = dis + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        mxNode = online.size() - 1;
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            mxNode = max({mxNode, u, v});
        }

        ll low = 0, high = 1e9;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid, k, online)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        return ans == INF ? -1 : ans;

    }
};