class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>s(m, string(n, '#'));
        for(int i = 0; i < n; i++) s[0][i] = '.';
        for(int i = 0; i < m; i++) s[i][n - 1] = '.';
        return s;
    }
};