class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>mx(n), mn(n);

        mn[0] = nums[0];
        for(int i = 1; i < n; i++){
            mn[i] = min(mn[i - 1], nums[i]);
        }

        mx[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            mx[i] = max(mx[i + 1], nums[i]);
        }

        for(int i = 0; i < n; i++){
            if(mn[i] < nums[i] && nums[i] < mx[i]) return true;
        }

        return false;
    }
};


// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int min1 = INT_MAX;
//         int min2 = INT_MAX;
//         for(int n : nums) {
//             if(n <= min1) {
//                 min1 = n;  // Update first minimum
//             } else if(n <= min2) {
//                 min2 = n;  // Update second minimum
//             } else {
//                 return true;  // Found a third number greater than both
//             }
//         }
//         return false;  // No triplet found
//     }
// };