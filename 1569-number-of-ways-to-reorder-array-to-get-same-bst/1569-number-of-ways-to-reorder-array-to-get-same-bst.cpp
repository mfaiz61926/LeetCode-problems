
class Solution {
private:
    static const long long MOD = 1'000'000'007LL;

    long long power(long long b, long long e) {
        long long r = 1;
        b %= MOD;

        while (e > 0) {
            if (e & 1)
                r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }

        return r;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        vector<int> born(n + 2, -1);

        for (int i = 0; i < n; i++)
            born[nums[i]] = i;

        long long fact = 1, sizes = 1;
        for (int k = 2; k <= n; k++)
            fact = fact * k % MOD;

        vector<int> st;
        st.push_back(0);

        for (int v = 1; v <= n + 1; v++) {
            while (born[st.back()] > born[v]) {
                st.pop_back();
                sizes = sizes * (v - st.back() - 1) % MOD;
            }
            st.push_back(v);
        }

        return (fact * power(sizes, MOD - 2) - 1 + MOD) % MOD;
    }
};