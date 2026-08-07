class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int l = n;
        int r = -1;

        stack<int> st;

        // Find left boundary
        // Maintain increasing stack
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Find right boundary
        // Maintain decreasing stack
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }

        if (r == -1)
            return 0;

        return r - l + 1;
    }
};