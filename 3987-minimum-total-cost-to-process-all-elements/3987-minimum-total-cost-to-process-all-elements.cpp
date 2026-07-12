class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    int minimumCost(vector<int>& nums, int k) {
        ll c = 0;
        ll cc = 1;
        ll x = k;

        for (int i = 0; i < nums.size(); i++) {
            if (x >= nums[i]) {
                x -= nums[i];
            } else {
                ll diff = nums[i] - x;
                ll numbOfTimes = (diff + k - 1) / k;

                ll an = cc + numbOfTimes - 1;

                ll a = an, b = an + 1;
                if (a & 1) b /= 2;
                else a /= 2;
                ll sum = (a % MOD) * (b % MOD) % MOD;

                a = cc - 1;
                b = cc;
                if (a & 1) b /= 2;
                else a /= 2;
                ll sum2 = (a % MOD) * (b % MOD) % MOD;

                c = (c + sum - sum2 + MOD) % MOD;

                cc += numbOfTimes;
                x += 1LL * k * numbOfTimes;
                x -= nums[i];
            }
        }

        return c;
    }
};