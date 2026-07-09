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
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            a.push_back({nums[i], i});
        }
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
            // int idx=upper_bound(val.begin(), val.end(), val[i]+maxDiff)-val.begin()-1;
            int idx = bs(val, val[i] + maxDiff);
            // if(idx == -1)continue;
            reach[i]=idx;
        }

        int LOG = 20;
        vector<vector<int>> up(n, vector<int>(LOG));
        for(int i = 0; i < n; i++)
            up[i][0] = reach[i];

        for(int j = 1; j < LOG; j++){
            for(int i = 0; i < n; i++){
                up[i][j] = up[up[i][j - 1]][j - 1];
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

            int cur = l;
            int steps = 0;

            for(int j = LOG - 1; j >= 0; j--){
                if(up[cur][j] < r){
                    cur = up[cur][j];
                    steps += (1 << j);
                }
            }

            if(reach[cur] >= r)
                ans.push_back(steps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};