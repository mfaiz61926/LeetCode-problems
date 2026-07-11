class Solution {
public:
    int  N = 55;
    vector<int>adj[55];
    vector<vector<int>>scc;
    int tin[55], low[55];
    stack<int>st;
    bool inStack[55];
    int timer;

    void dfs(int u){
        tin[u] = low[u] = ++timer;
        st.push(u);
        inStack[u] = true;

        for(int v : adj[u]){
            if(!tin[v]){
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
            else if(inStack[v]){
                low[u] = min(low[u], tin[v]);
            }
        }

        if(low[u] == tin[u]){
            int v = -1;
            scc.push_back({});

            while(v != u){
                v = st.top();
                st.pop();
                scc.back().push_back(v);
                inStack[v] = false;
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
            for(int i = 0; i < N; i++) adj[i].clear();
            for(int i = 0; i < N; i++){
                tin[i] = low[i] = 0;
                inStack[i] = false;
            }
            while(!st.empty()) st.pop();

            for(auto &i : edges){
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(i[0]);
            }

            for(int i = 0; i < n; i++){
                if(!tin[i]) dfs(i);
            }

            int cnt = 0;
            for(auto &i : scc){
                int k = i.size();
                bool ok = true;

                for(auto it : i){
                    if(adj[it].size() != k - 1){
                        ok = false;
                        break;
                    }
                }
                if(ok) cnt++;
            }

            return cnt;
    }
};