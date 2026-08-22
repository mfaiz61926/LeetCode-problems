class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int x = n;
        int p = 1;
        while(x > 0){
            int d = x % 10;
            p *= d;
            sum += d;
            x /= 10;
        }
        return n % (sum + p) == 0;
    }
};