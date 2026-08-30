class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn, mx;
        int mnn = *min_element(nums.begin(), nums.end());
        int mxn = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == mnn) mn = i;
            if(nums[i] == mxn) mx = i;
        }
        if(mn > mx) swap(mx, mn);
        return min({mx + 1, n - mn, mn + 1 + n - mx});
    }
};