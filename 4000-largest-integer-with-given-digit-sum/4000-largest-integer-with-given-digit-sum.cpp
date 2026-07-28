class Solution {
public:
    int largestInteger(int n, int s) {
        string l;
        for(int i = 0; i < n; i++) l += '9';
        for(int i = stoi(l); i >= 0; i--){
            int sum = 0;
            int x = i;
            while(x){
                sum += x % 10;
                x /= 10;
            }
            if(sum == s) return i;
        }
        return -1;
    }
};