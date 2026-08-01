// class Solution {
// public:
//     string winningPlayer(int x, int y) {
//         int i = 1;
//         while(true){
//             if(x < 1 || y < 4) break;
//             x--, y -= 4;
//             i++;
//         }
//         return i&1 ? "Bob" : "Alice";
//     }
// };

class Solution {
public:
    string winningPlayer(int x, int y) {
        return min(x, y/4) & 1 ? "Alice" : "Bob";
    }
};