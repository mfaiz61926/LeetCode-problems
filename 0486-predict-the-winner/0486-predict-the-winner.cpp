class Solution {
public:
    int n;
    int f(int i , int j, vector<int>&a){
        if(i == j) return a[i];

        //p1 takes left
        int left = a[i] - f(i + 1, j, a);
        int right = a[j] - f(i, j - 1, a);

        return max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        return f(0, n - 1, nums) >= 0;
    }
};