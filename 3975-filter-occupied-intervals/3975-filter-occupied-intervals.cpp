class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& v, int fs, int fe) {
        sort(v.begin(), v.end());
        vector<vector<int>>merge;
        for(auto &it : v){
            if(merge.empty() || merge.back()[1] + 1 < it[0]){
                merge.push_back(it);
            }
            else merge.back()[1] = max(merge.back()[1], it[1]);
        }

        vector<vector<int>>ans;
        for(auto &it : merge){
            int l = it[0], r = it[1];
            //case 1: interval lies in fs and fe inclusive
            if(fs <= l && r <= fe) continue;
            //case 2: out of fs and fe
            if(l > fe || r < fs){
                ans.push_back(it);
            }
            //case: l and r in fs and fe
            else if(l < fs && fe < r){
                ans.push_back({l, fs - 1});
                ans.push_back({fe + 1, r});
            }
            //case 4: l < fs
            else if(l < fs){
                ans.push_back({l, fs - 1});
            }
            else{ // fs <= l
                ans.push_back({fe + 1, r});
            }

        }
        return ans;
    }
};