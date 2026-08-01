class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {

        vector<vector<int>>freq(n, vector<int>(11, 0));

        for(auto &p : pick){
            int player = p[0];
            int color = p[1];
            freq[player][color]++;
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int mx = *max_element(freq[i].begin(), freq[i].end());
            if(mx > i) cnt++;
        }

        return cnt;
    }
};