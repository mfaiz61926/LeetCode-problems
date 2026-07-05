class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int>pre(n + 1), suf(n + 1);
        int j = 0;
        pre[0] = 0;
        for(int i = 0; i < n; i++){
            while(j < m && t[j] != s[i]) j++;
            pre[i + 1] = (j == m ? m + 1 : ++j);
        }
        if(pre[n] != m + 1) return true;
        j = m - 1;
        suf[n] = m;
        for(int i = n - 1; i >= 0; i--){
            while(j >= 0 && t[j] != s[i]) j--;
            suf[i] = (j < 0 ? -1 : j--);
        }

        for(int i = 0; i < n; i++){
                if(pre[i] != m + 1 && suf[i + 1] != -1 && pre[i] < suf[i  + 1]) return true;
        }
        return false;
    }
};