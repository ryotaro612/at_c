#include <bits/stdc++.h>
using namespace std;
// int main() {
//   int h, w;
//   cin >> h >> w;
//   vector<string> board(h);
//   for(int i = 0;i<h;i++)
//     cin >> board[i];

//   for(int i = 0;i<h;i++) {
//     for(int j= 0;j<w;j++) {
//       if(board[i][j] == '#')
//         continue;
//       int num = 0;
//       if(0<i) {
//         if(0 < j && board[i-1][j-1] == '#')
//           num++;
//         if(board[i-1][j] == '#')
//           num++;
//         if(j<w-1 && board[i-1][j+1] == '#')
//           num++;
//       }
//       if(0 < j && board[i][j-1] == '#')
//         num++;
//       if(j < w-1 && board[i][j+1] == '#')
//         num++;
//       if(i < h-1) {
//         if(0 < j && board[i+1][j-1] == '#')
//           num++;
//         if(board[i+1][j] == '#')
//           num++;
//         if(j<w-1 && board[i+1][j+1] == '#')
//           num++;
//       }
//       board[i][j] = num + '0';
//     }
//   }
//   for(int i = 0;i<h;i++)
//     cout << board[i] << endl;
//   return 0;
// }
