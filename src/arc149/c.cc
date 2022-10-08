// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;
// #define all(x) x.begin(), x.end()

// int main() {
//   int N;
//   cin >> N;

//   vector<vector<int>> A(N, vector<int>(N));

//   if (N == 3) {
//     A[0] = {5, 9, 1};
//     A[1] = {3, 7, 8};
//     A[2] = {6, 2, 4};
//   }
//   if (N == 4) {
//     A[0] = {9, 11, 13, 15};
//     A[1] = {1, 3, 5, 7};
//     A[2] = {8, 6, 4, 2};
//     A[3] = {10, 12, 14, 16};
//   }
//   if (N == 5) {
//     A[0] = {5, 7, 11, 13, 17};
//     A[1] = {19, 23, 25, 21, 1};
//     A[2] = {3, 9, 15, 24, 8};
//     A[3] = {6, 12, 18, 2, 4};
//     A[4] = {10, 14, 16, 20, 22};
//   }
//   if (N >= 6) {
//     vector<int> B;
//     for (int x = 1; x <= N * N; ++x) {
//       if (x % 2 == 1 && x % 3 != 0)
//         B.emplace_back(x);
//     }
//     for (int x = 1; x <= N * N; ++x) {
//       if (x % 2 == 1 && x % 3 == 0)
//         B.emplace_back(x);
//     }
//     for (int x = 1; x <= N * N; ++x) {
//       if (x % 2 == 0 && x % 3 == 0)
//         B.emplace_back(x);
//     }
//     for (int x = 1; x <= N * N; ++x) {
//       if (x % 2 == 0 && x % 3 != 0)
//         B.emplace_back(x);
//     }
//     for (int i = 0; i < N; ++i)
//       for (int j = 0; j < N; ++j)
//         A[i][j] = B[N * i + j];
//   }

//   for (int i = 0; i < N; ++i) {
//     for (int j = 0; j < N; ++j) {
//       if (j)
//         cout << " ";
//       cout << A[i][j];
//     }
//     cout << '\n';
//   }
// }
