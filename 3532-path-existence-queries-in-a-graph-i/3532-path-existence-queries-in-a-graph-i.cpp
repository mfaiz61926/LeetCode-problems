class DSU {
    public:
        vector<int>parent, size;
        DSU(int n){
            parent.resize(n + 1);
            size.resize(n + 1);

            for(int i = 0; i <= n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node){
            if(parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unite(int u, int v){
            int up = findUPar(u);
            int vp = findUPar(v);

            if(up == vp) return;

            if(size[up] > size[vp]){
                parent[vp] = up;
                size[up] += size[vp];
            }
            else {
                parent[up] = vp;
                size[vp] += size[up];
            }
        }
};

class Solution {
public:
    int bs(vector<int>&nums, int val){
        int n = nums.size();
        int ans = -1; 
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] <= val){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        DSU ds(n + 1);

        for(int i = 0; i < n; i++){
            int val = nums[i] + maxDiff;
            int idx = bs(nums, val);
            if(idx == -1) continue;
            // for(int j = i; j <= idx; j++){
            //     ds.unite(i, j);
            // }
            ds.unite(i, idx);
        }

        vector<bool> ans;
        for(auto &it : queries){
            int u = it[0], v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};