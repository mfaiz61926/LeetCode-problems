class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                set<int>st;
                for(int k = i; k <= j; k++){
                    st.insert(nums[k]);
                }
                int m = st.size();
                cnt += m * m;
            }
        }

        return cnt;
    }
};