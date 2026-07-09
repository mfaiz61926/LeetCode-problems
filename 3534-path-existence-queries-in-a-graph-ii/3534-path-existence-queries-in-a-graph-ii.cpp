class Solution {
public:
    int bs(vector<int>&v, int val){
        int n = v.size();
        int ans = 0;
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(v[mid] <= val){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>a;
        for(int i = 0; i < n ; i++){
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        vector<int>pos(n), val(n);

        for(int i = 0; i < n; i++){
            val[i] = a[i].first;
            pos[a[i].second] = i;
        }
        vector<int>reach(n);
        for(int i = 0; i < n; i++){
            int idx = bs(val, maxDiff + val[i]);
            reach[i] = idx;
        }

        int mx_bit = 20;
        vector<vector<int>>up(n, vector<int>(mx_bit));
        for(int i = 0; i < n; i++){
            up[i][0] = reach[i];
        }
        for(int i = 1; i < mx_bit; i++){
            for(int u = 0; u < n; u++){
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
        }

        vector<int>ans;
        for(auto &it : queries){
            int u = it[0], v = it[1];

            int l = pos[u];
            int r = pos[v];

            if(l > r) swap(l, r);
            if(l == r){
                ans.push_back(0);
                continue;
            }

            if(reach[l] == l){
                ans.push_back(-1);
                continue;
            }

            int cur = l;
            int steps = 0;

            for(int j = mx_bit - 1; j >= 0; j--){
                if(up[cur][j] < r){
                    cur = up[cur][j];
                    steps += (1 << j);
                }
            }

            if(reach[cur] >= r){
                ans.push_back(steps + 1);
            }
            else ans.push_back(-1);

        }

        return ans;
    }
};