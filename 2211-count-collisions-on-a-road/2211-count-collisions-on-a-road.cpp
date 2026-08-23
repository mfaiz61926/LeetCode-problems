// class SolutionStack {
// public:
//     int countCollisions(string directions) {
//         int n = directions.size();
//         stack<char>st;
//         int cnt = 0;
//         for(int i = 0; i < n; i++){
//             char c = directions[i];
//             if(st.empty() && (c == 'S' || c == 'R')) st.push(c);

//             else if(!st.empty() && c == 'L' && st.top() == 'R'){
//                 cnt += 2;
//                 st.pop();
//                 while(!st.empty() && st.top() == 'R'){
//                     cnt++;
//                     st.pop();
//                 }
//                 st.push('S');
//             }
//             else if(!st.empty() && c == 'L' && st.top() == 'S'){
//                 cnt += 1;
//             }
//             else if(c == 'R'){
//                  st.push(c);
//             }
//             else if(!st.empty() && c == 'S' && st.top() == 'R'){
//                 while(!st.empty() && st.top() == 'R'){
//                     cnt++;
//                     st.pop();
//                 }
//                 st.push('S');
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int cnt = 0;
        int i = 0, j = n - 1;

        while(i < n && directions[i] == 'L') i++;
        while(j >= 0 && directions[j] == 'R') j--;

        for(int k = i; k <= j; k++){
            if(directions[k] != 'S') cnt++;
        }

        return cnt;
    }
};