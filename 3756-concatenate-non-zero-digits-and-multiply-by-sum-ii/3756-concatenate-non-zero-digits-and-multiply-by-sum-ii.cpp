class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> pow10(n + 1, 1);
        for(int i = 1; i <= n; i++){
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long>sum(n, 0), num(n, 0), cnt(n, 0);
        if(s[0] != '0'){
            int d = s[0] - '0';
            sum[0] = d;
            num[0] = d;
            cnt[0] = 1;
        }
        for(int i = 1; i < n; i++){
            sum[i] = sum[i - 1];
            num[i] = num[i - 1];
            cnt[i] = cnt[i - 1];

            if(s[i] != '0'){
                int d = s[i] - '0';
                sum[i] = (sum[i] + d) % MOD;
                num[i] = (num[i] * 10 + d) % MOD;
                cnt[i]++;
            }
        }

        vector<int>ans;
        for(auto &it : queries){
            int l = it[0], r = it[1];
            
            long long sum1 = sum[r] - (l ? sum[l - 1] : 0);
            sum1 = (sum1 % MOD + MOD) % MOD;

            int digits = cnt[r] - (l ? cnt[l - 1] : 0);

            long long number;
            if(l == 0) number = num[r];
            else {
                number = (num[r] - num[l - 1] * pow10[digits]) % MOD;
                if (number < 0) number += MOD;
            }

            ans.push_back(number * sum1 % MOD);
        }
        return ans;
    }
};