
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        multiset<int> st;
        int ans = INT_MAX;

        for (int j = l; j <= n; j++) {

            // Add prefix index j-l
            st.insert(pref[j - l]);

            // Remove prefix index j-r-1
            if (j - r - 1 >= 0) {
                st.erase(st.find(pref[j - r - 1]));
            }

            // Find largest prefix sum strictly smaller than pref[j]
            auto it = st.lower_bound(pref[j]);

            if (it != st.begin()) {
                --it;
                ans = min(ans, pref[j] - *it);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
