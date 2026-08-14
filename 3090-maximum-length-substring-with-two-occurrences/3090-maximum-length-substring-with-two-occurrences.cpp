class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                vector<int>f(26);
                for(int k = i; k <= j; k++){
                    f[s[k] - 'a']++;
                }
                bool ok = true;
                for(int i = 0; i < 26; i++){
                    if(f[i] && f[i] > 2) ok = false;
                }
                if(ok) mx = max(mx, j - i + 1);
            }
        }
        return mx;
    }
};