#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
void sub(int current, vector<bool> &visit) {
  int k;
  cin >> k;
  vector<int> v(k);
  rep(i, k) cin >> v[i];
  rep(i, k) {
    if (visit[v[i]] == false) {
      cout << v[i] << endl;
      if (v[i] == int(visit.size()) - 1)
        exit(0);
      visit[v[i]] = true;
      sub(v[i], visit);
      cout << current << endl;
      int x;
      cin >> x;
      int temp;
      rep(j, x) { cin >> temp; }
    }
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> visit(n + 1, false);
  visit[1] = true;
  sub(1, visit);
  return 0;
}
#endif
