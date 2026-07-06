class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<int>vis(n, 0);
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            for(int j = 0; j < n; j++){
                if(i != j && !vis[j] && intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1]){
                    vis[j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]) cnt++;
        }
        return cnt;
    }
};