#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll pow3(int n) {
  ll result = 1ll;
  rep(i, n) result *= 3ll;

  return result;
}

vector<string> solve(int n, int l) {

  vector<string> sv(3 * n);

  rep(i, l) {
    sort(sv.begin(), sv.end(), greater<string>());
    vector<int> dv(3, n);
    int j = 0;
    int digit = 0;
    while (j < 3 * n) {
      for (int k = 0; k < pow3(l - 1 - i); k++) {
        sv[j++].append(to_string(digit));
        dv[digit]--;
        if (dv[digit] == 0 || 3 * n <= j)
          break;
      }
      digit = (digit + 1) % 3;
    }
  }
  sort(sv.begin(), sv.end());
  return sv;
}

#ifdef ONLINE_JUDGE
int main() {
  int n, l;
  cin >> n >> l;
  vector<string> res = solve(n, l);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
