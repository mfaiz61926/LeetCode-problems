class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& v, int fStart, int fEnd) {
        int n = v.size();
        sort(v.begin(), v.end());

        vector<vector<int>>ans;
        if(n == 0) return ans;
        ans.push_back(v[0]);
        for(int i = 1; i < n; i++){
            auto it = v[i];
            int x = it[0], y = it[1];
            int a = ans.back()[0], b = ans.back()[1];
            if(b + 1 < x) ans.push_back(it);
            else {
                ans.back()[1] = max(ans.back()[1], y);
            }
        }
        bool s = false, e = false;
        vector<vector<int>>res;
        for(auto &it : ans){
            if(it[0] >= fStart && it[1] <= fEnd)continue;
            else if(it[1] < fStart || it[0] > fEnd){
                res.push_back(it);
            }
            else if(it[0] < fStart && fEnd < it[1]){
                res.push_back({it[0], fStart - 1});
                res.push_back({fEnd + 1, it[1]});
            }
            else if(it[0] < fStart){
                res.push_back({it[0], fStart - 1});
            }
            else res.push_back({fEnd + 1, it[1]});
            
        }
        return res;
    }
};