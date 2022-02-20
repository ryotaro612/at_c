#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool is_prime(const unsigned n) {
  switch (n) {
  case 0: // fall-through
  case 1:
    return false;
  case 2: // fall-through
  case 3:
    return true;
  } // n > 3 が保証された

  if (n % 2 == 0 || n % 3 == 0)
    return false;
  // n は 2 と 3 のいずれの倍数でもないことが保証された
  // これより n は (6の倍数)-1 か (6の倍数)+1 である

  // 6の倍数前後の数を使って試し割りをする
  for (unsigned i = 5; i * i <= n; i += 6) {
    if (n % i == 0)
      return false; // (6の倍数)-1
    if (n % (i + 2) == 0)
      return false; // (6の倍数)+1
  }

  return true;
}

string solve(int a, int b, int c, int d) {
  vector<vector<bool>> win_takahashi(101, vector<bool>(101));
  for (int ta = 1; ta <= 100; ta++) {
    for (int ao = 1; ao <= 100; ao++) {
      if (is_prime(ta + ao)) {
        win_takahashi[ta][ao] = false;
      } else {
        win_takahashi[ta][ao] = true;
      }
    }
  }
  // 高橋くんがえらぶ
  for (int i = a; i <= b; i++) {
    bool win_ta = true;
    // 青木くんがえらぶ
    for (int j = c; j <= d; j++) {
      if (win_takahashi[i][j] == false)
        win_ta = false;
    }
    if (win_ta) {
      return "Takahashi";
    }
  }
  return "Aoki";
}

#ifdef ONLINE_JUDGE
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << solve(a, b, c, d) << endl;
  return 0;
}
#endif
