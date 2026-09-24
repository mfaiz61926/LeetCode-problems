class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int ds = 0;
            int x = nums[i];
            while(x){
                ds += x % 10;
                x /= 10;
            }
            if(ds == i) return i;
        }
        return -1;
    }
};