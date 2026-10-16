const int MOD = 1e9 + 7;
using ll = long long;

struct SegTree {
    vector<ll> lzy;
    vector<ll> sum;
    vector<ll> sqr;
    int n;

    SegTree(int _n) : n(_n) {
        // this.n = _n
        lzy.resize(4*n, 0);
        sum.resize(4*n, 0);
        sqr.resize(4*n, 0);
    }

    void update_lzy(int l, int r, int i){
        if(l != r){
            lzy[2 * i + 1] += lzy[i];
            lzy[2 * i + 2] += lzy[i];
        }

        ll gap = r - l + 1;
        ll new_sum = sum[i] + lzy[i] * gap;
        ll new_sqr = sqr[i] + lzy[i] * sum[i] * 2 + lzy[i] * lzy[i] * gap;

        sum[i] = new_sum % MOD;
        sqr[i] = new_sqr % MOD;
        lzy[i] = 0;
    }

    void AddOne(int x, int y, int l = 0, int r = -1, int i = 0){
        if(r == -1) r += n;
        update_lzy(l, r, i);

        if(r < x || y < l) return;
        if(x <= l && r <= y){
            lzy[i] = 1;
            return update_lzy(l, r, i);
        }

        int m = (l + r) >> 1;
        AddOne(x, y, l, m, 2 * i + 1);
        AddOne(x, y, m + 1, r, 2 * i + 2);

        sum[i] = (sum[2 * i + 1] + sum[2 * i + 2]) % MOD;
        sqr[i] = (sqr[2 * i + 1] + sqr[2 * i + 2]) % MOD;

    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        vector<int> last_pos(100001, -1);

        SegTree tree(n);
        int ans = 0;

        for(int j = 0; j < n; j++){
            int start = last_pos[nums[j]] + 1;
            int end = j;

            tree.AddOne(start, end); //update in segtree

            ans = (ans + tree.sqr[0]) % MOD;

            last_pos[nums[j]] = j;
        }

        return ans;
    }
};