class Solution {
public:
    int g(int a, int b){
        if(b == 0) return a;
        return g(b, a % b);
    }

    int gcdOfOddEvenSums(int n) {
        int sumo = 0, sume = 0;
        for(int i = 0; i <= 2*n; i++){
            if(i & 1) sumo += i;
            else sume += i;
        }

        return g(sumo, sume);
    }
};