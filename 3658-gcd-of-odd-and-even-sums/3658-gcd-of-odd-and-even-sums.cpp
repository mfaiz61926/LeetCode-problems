class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumo = 0, sume = 0;
        for(int i = 0; i <= 2*n; i++){
            if(i & 1) sumo += i;
            else sume += i;
        }

        return gcd(sumo, sume);
    }
};