class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; i <= 100000; i++){
            int p = 1;
            int x = i;
            while(x){
                int d = x % 10;
                p *= d;
                x /= 10;
            }
            if(p % t == 0) return i;
        }
        return -1;
    }
};