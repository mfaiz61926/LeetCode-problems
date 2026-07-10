class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<pair<int,int>>v;
        int cnt = 0;
        int s = -1;
        bool ok = false;
        for(int i = 0; i < n; i++){
            if(s == -1 && corridor[i] == 'S'){
                s = i;
                cnt++;
            }
            else if(corridor[i] == 'S'){
                cnt++;
                if(cnt == 2){
                    ok = true;
                    v.push_back({s, i});
                    cnt = 0;
                    s = -1;
                }
            }
        }
        if(s != -1) return 0;
        if(!ok) return 0;
        int MOD = 1e9 + 7;
        long long ways  = 1;
        for(int i = 1; i < v.size(); i++){
            int len = v[i].first - v[i - 1].second;
            ways = len * ways % MOD;
        }

        return ways;
    }
};