class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        multiset<int>st;
        for(int i = 0; i < k; i++) st.insert(nums[i]);
        for(int i = k; i < nums.size(); i++){
            res.push_back(*st.rbegin());
            st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
        }
        res.push_back(*st.rbegin());
        return res;
    }
};