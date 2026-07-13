class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), reqcnt = t.size();
        if(reqcnt > n) return "";
        int start_idx = -1;
        int mnw = 1e9;
        map<char, int>mp;
        for(auto &c : t) mp[c]++;

        int l = 0;
        for(int r = 0; r < n; r++){
            if(mp[s[r]] > 0) reqcnt--;
            mp[s[r]]--;
            while(reqcnt == 0){
                if(mnw > r - l + 1){
                    mnw = r - l + 1;
                    start_idx = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) reqcnt++;
                l++;
            }
        }
        return mnw == 1e9 ? "" : s.substr(start_idx, mnw);
    }
};