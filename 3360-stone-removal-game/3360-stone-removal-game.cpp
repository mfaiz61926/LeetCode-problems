class Solution {
public:
    bool canAliceWin(int n) {
        int x = 0;
        int t = 10;
        while(n > 0){
            if(x == 0){
                if(t <= n) n -= t;
                else return false;
            }
            else{
                if(t <= n) n -= t;
                else return true;
            }   
            x ^= 1;        
            t--;
        }
        return x == 1;
    }   
};