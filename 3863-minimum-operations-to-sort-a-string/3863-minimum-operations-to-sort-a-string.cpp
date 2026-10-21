class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(n == 1) return 0;
        if(n == 2 && s[0] > s[1]) return -1;

        string t = s;
        sort(t.begin(), t.end());
        if(s == t) return 0;
        
        if(s[0] == t[0] || s[n - 1] == t[n - 1]) return 1;

        char mx = t[n - 1];
        char mn = t[0];

        bool mx0 = (s[0] == mx && (s.rfind(mx) == 0));
        bool mnl = (s[n - 1] == mn && (s.find(mn) == n - 1));

        if(mx0 && mnl) return 3;

        return 2;
    }
};