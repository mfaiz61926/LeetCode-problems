class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        priority_queue<int>cur, prev;

        for(int i = 0; i < k; i++){
            cur.push(nums[i]);
        }

        ans.push_back(cur.top());

        for(int i = k; i < n; i++){
            int remove = nums[i - k];
            prev.push(remove);
            cur.push(nums[i]);

            while(!prev.empty() && cur.top() == prev.top()){
                cur.pop();
                prev.pop();
            }

            ans.push_back(cur.top());
        }
        return ans;
    }
};