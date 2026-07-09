class DSU {
public:
    vector<int> parent, sz, mx;

    DSU(int n, vector<int>& nums){
        parent.resize(n);
        sz.assign(n,1);
        mx = nums;

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int u,int v){
        u=find(u);
        v=find(v);

        if(u==v) return;

        if(sz[u]<sz[v]) swap(u,v);

        parent[v]=u;
        sz[u]+=sz[v];
        mx[u]=max(mx[u],mx[v]);
    }
};

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n), suf(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = max(pre[i - 1], nums[i]);
        }
        suf[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suf[i] = min(suf[i + 1], nums[i]);
        }

        
        vector<int>ans;
        DSU ds(n, nums);
    
        for(int i = 0; i < n - 1; i++){
            if(pre[i] > suf[i + 1]) ds.unite(i, i + 1);
        }

        for(int i = 0; i < n; i++){
            ans.push_back(ds.mx[ds.find(i)]);
        }
           

        return ans;
    }
};