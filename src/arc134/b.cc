#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(arg) cout << #arg << ": " << arg << endl;

int sum(int i, char c, vector<vector<int>> &bits) {
  int res = 0;
  while (0 < i) {
    res += bits[i][c - 'a'];
    i -= i & -i;
  }
  return res;
}

void add(int i, int x, char c, vector<vector<int>> &bits) {
  int n = bits.size() - 1;
  while (i <= n) {
    bits[i][c - 'a'] += x;
    i += i & -i;
  }
}

void rec(string &res, int from, int to, vector<vector<int>> &bits) {
  if (to - from <= 1)
    return;
  // cout << "from: " << from << ", to: " << to << endl;
  for (int i = 0; i < res[from] - 'a'; i++) {
    int num_alpha = sum(to, i + 'a', bits) - sum(from + 1, i + 'a', bits);
    if (num_alpha) {
      if (res[to - 1] == i + 'a') {
        add(from + 1, -1, res[from], bits);
        add(to, 1, res[from], bits);

        add(to, -1, res[to - 1], bits);
        add(from + 1, 1, res[to - 1], bits);

        swap(res[from], res[to - 1]);
        rec(res, from + 1, to - 1, bits);
      } else {
        rec(res, from, to - 1, bits);
      }
      return;
    }
  }
  // cout << "not found" << endl;
  rec(res, from + 1, to, bits);
  return;
}

string solve(int n, string &s) {
  string res(s);
  vector<vector<int>> bits(n + 1, vector<int>(26, 0));

  rep(i, n) { add(i + 1, 1, s[i], bits); }
  rec(res, 0, n, bits);
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s;
  cin >> n >> s;
  cout << solve(n, s) << endl;
}
#endif
