class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            res += ((i + 1) * (26 - (s[i] - 'a')));
        }
        return res;
    }
};