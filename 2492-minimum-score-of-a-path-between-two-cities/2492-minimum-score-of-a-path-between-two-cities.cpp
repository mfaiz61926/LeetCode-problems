class DisjointUnionSet {
    public :
        vector<int>parent, size, mn;
        DisjointUnionSet(int n){
            parent.resize(n + 1);
            size.resize(n + 1);
            mn.resize(n + 1, 1e6);

            for(int i = 0; i <= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            else {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
};

class Solution {
public:
    const int INF = 1e9 + 7;
    vector<pair<int, int>>adj[100005];
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointUnionSet ds(n);

        for(auto &it : roads){
            ds.unionBySize(it[0], it[1]);
        }
        for(auto &it : roads){
            int par = ds.findUPar(it[0]);
            ds.mn[par] = min(ds.mn[par], it[2]);
        }
        return ds.mn[ds.findUPar(n)];   
    }
};