class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        vector<int>seen(3, -1); 
        for(int i = 0; i < n; i++){
            seen[s[i] - 'a'] = i;
            if(seen[0] != -1 && seen[1] != -1 && seen[2] != -1){
                cnt = cnt + 1 + min({seen[0], seen[1], seen[2]});
            }
        }
        return cnt;
    }
};