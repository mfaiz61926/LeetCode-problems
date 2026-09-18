class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<int> adj[],
             stack<int>& st) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

    void dfs3(int node, vector<int>& comp,
              vector<int>& sccId,
              int id,
              vector<int> adjT[]) {

        sccId[node] = id;
        comp.push_back(node);

        for (auto it : adjT[node]) {
            if (sccId[it] == -1) {
                dfs3(it, comp, sccId, id, adjT);
            }
        }
    }

public:
    vector<string> maxNumOfSubstrings(string S) {

        vector<int> mins(26, INT_MAX);
        vector<int> maxs(26, -1);
        vector<int> exists(26, 0);

        int n = S.size();

        vector<vector<int>> prefix(n + 1, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {

            prefix[i + 1] = prefix[i];
            prefix[i + 1][S[i] - 'a']++;

            mins[S[i] - 'a'] = min(mins[S[i] - 'a'], i);
            maxs[S[i] - 'a'] = max(maxs[S[i] - 'a'], i);

            exists[S[i] - 'a'] = 1;
        }

        vector<int> adj[26];

        // Build graph
        for (int i = 0; i < 26; i++) {

            if (!exists[i]) continue;

            for (int j = 0; j < 26; j++) {

                if (prefix[maxs[i] + 1][j] - prefix[mins[i]][j] > 0) {
                    adj[i].push_back(j);
                }
            }
        }

        // Kosaraju step 1
        vector<int> vis(26, 0);
        stack<int> st;

        for (int i = 0; i < 26; i++) {
            if (exists[i] && !vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // Transpose graph
        vector<int> adjT[26];

        for (int i = 0; i < 26; i++) {
            for (auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        // Kosaraju step 2
        vector<int> sccId(26, -1);
        vector<vector<int>> comps;

        int batch = 0;

        while (!st.empty()) {

            int node = st.top();
            st.pop();

            if (sccId[node] == -1) {

                vector<int> comp;
                dfs3(node, comp, sccId, batch, adjT);

                comps.push_back(comp);
                batch++;
            }
        }

        // Out-degree of SCC DAG
        vector<int> degree(batch, 0);

        for (int u = 0; u < 26; u++) {

            if (!exists[u]) continue;

            for (auto v : adj[u]) {

                if (sccId[u] != sccId[v]) {
                    degree[sccId[u]]++;
                }
            }
        }

        vector<string> ans;

        for (int id = batch - 1; id >= 0; id--) {

            if (degree[id] == 0) {

                int L = INT_MAX;
                int R = -1;

                for (int ch = 0; ch < 26; ch++) {

                    if (sccId[ch] == id) {
                        L = min(L, mins[ch]);
                        R = max(R, maxs[ch]);
                    }
                }

                ans.push_back(S.substr(L, R - L + 1));
            }
        }

        return ans;
    }
};




// class Solution {
// private:

//     void tarjan(
//         int u,
//         vector<int> adj[],
//         vector<int>& tin,
//         vector<int>& low,
//         vector<int>& sccId,
//         vector<bool>& inStack,
//         stack<int>& st,
//         int& timer,
//         int& sccCount,
//         vector<vector<int>>& comps
//     ) {
//         tin[u] = low[u] = timer++;

//         st.push(u);
//         inStack[u] = true;

//         for (int v : adj[u]) {

//             // v is not visited
//             if (tin[v] == -1) {

//                 tarjan(
//                     v,
//                     adj,
//                     tin,
//                     low,
//                     sccId,
//                     inStack,
//                     st,
//                     timer,
//                     sccCount,
//                     comps
//                 );

//                 low[u] = min(low[u], low[v]);
//             }

//             // Back edge to a node currently in stack
//             else if (inStack[v]) {

//                 low[u] = min(low[u], tin[v]);
//             }
//         }

//         // u is the root of an SCC
//         if (low[u] == tin[u]) {

//             vector<int> comp;

//             while (true) {

//                 int v = st.top();
//                 st.pop();

//                 inStack[v] = false;

//                 sccId[v] = sccCount;
//                 comp.push_back(v);

//                 if (v == u)
//                     break;
//             }

//             comps.push_back(comp);
//             sccCount++;
//         }
//     }


// public:

//     vector<string> maxNumOfSubstrings(string S) {

//         int n = S.size();

//         // -----------------------------------------
//         // 1. First and last occurrence of characters
//         // -----------------------------------------

//         vector<int> mins(26, INT_MAX);
//         vector<int> maxs(26, -1);
//         vector<int> exists(26, 0);

//         // prefix[i][j] = number of character j
//         // in S[0 ... i-1]
//         vector<vector<int>> prefix(
//             n + 1,
//             vector<int>(26, 0)
//         );

//         for (int i = 0; i < n; i++) {

//             prefix[i + 1] = prefix[i];

//             int ch = S[i] - 'a';

//             prefix[i + 1][ch]++;

//             mins[ch] = min(mins[ch], i);
//             maxs[ch] = max(maxs[ch], i);

//             exists[ch] = 1;
//         }


//         // -----------------------------------------
//         // 2. Build dependency graph
//         // -----------------------------------------

//         vector<int> adj[26];

//         for (int i = 0; i < 26; i++) {

//             if (!exists[i])
//                 continue;

//             for (int j = 0; j < 26; j++) {

//                 // Does character j occur inside
//                 // [first(i), last(i)] ?
//                 int count =
//                     prefix[maxs[i] + 1][j]
//                     - prefix[mins[i]][j];

//                 if (count > 0) {
//                     adj[i].push_back(j);
//                 }
//             }
//         }


//         // -----------------------------------------
//         // 3. Tarjan's algorithm
//         // -----------------------------------------

//         vector<int> tin(26, -1);
//         vector<int> low(26, -1);
//         vector<int> sccId(26, -1);

//         vector<bool> inStack(26, false);

//         stack<int> st;

//         int timer = 0;
//         int sccCount = 0;

//         vector<vector<int>> comps;

//         for (int i = 0; i < 26; i++) {

//             if (exists[i] && tin[i] == -1) {

//                 tarjan(
//                     i,
//                     adj,
//                     tin,
//                     low,
//                     sccId,
//                     inStack,
//                     st,
//                     timer,
//                     sccCount,
//                     comps
//                 );
//             }
//         }


//         // -----------------------------------------
//         // 4. Find out-degree of every SCC
//         // -----------------------------------------

//         vector<int> degree(sccCount, 0);

//         for (int u = 0; u < 26; u++) {

//             if (!exists[u])
//                 continue;

//             for (int v : adj[u]) {

//                 if (sccId[u] != sccId[v]) {
//                     degree[sccId[u]]++;
//                 }
//             }
//         }


//         // -----------------------------------------
//         // 5. SCCs with out-degree 0
//         // -----------------------------------------

//         vector<string> ans;

//         for (int id = 0; id < sccCount; id++) {

//             if (degree[id] != 0)
//                 continue;

//             int L = INT_MAX;
//             int R = -1;

//             // Find range of this SCC
//             for (int ch : comps[id]) {

//                 L = min(L, mins[ch]);
//                 R = max(R, maxs[ch]);
//             }

//             ans.push_back(
//                 S.substr(L, R - L + 1)
//             );
//         }

//         return ans;
//     }
// };