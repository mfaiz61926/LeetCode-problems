class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int,int>> a;
        for(int i=0;i<n;i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        // pos[original index] = position in sorted array
        vector<int> pos(n);

        vector<int> val(n);
        for(int i=0;i<n;i++){
            val[i]=a[i].first;
            pos[a[i].second]=i;
        }

        // farthest reachable index in one edge
        vector<int> reach(n);

        for(int i=0;i<n;i++){
            int idx=upper_bound(val.begin(), val.end(), val[i]+maxDiff)-val.begin()-1;
            reach[i]=idx;
        }

        const int LOG=20;

        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i=0;i<n;i++)
            up[0][i]=reach[i];

        for(int k=1;k<LOG;k++){
            for(int i=0;i<n;i++){
                up[k][i]=up[k-1][ up[k-1][i] ];
            }
        }

        vector<int> ans;

        for(auto &q:queries){

            int l=pos[q[0]];
            int r=pos[q[1]];

            if(l>r) swap(l,r);

            if(l==r){
                ans.push_back(0);
                continue;
            }

            if(reach[l]==l){
                ans.push_back(-1);
                continue;
            }

            int cur=l;
            int steps=0;

            for(int k=LOG-1;k>=0;k--){
                if(up[k][cur]<r){
                    if(up[k][cur]==cur) continue;
                    cur=up[k][cur];
                    steps+=(1<<k);
                }
            }

            if(reach[cur]>=r)
                ans.push_back(steps+1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};