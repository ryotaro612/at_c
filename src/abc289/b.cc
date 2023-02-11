#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

#ifdef ONLINE_JUDGE
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> av(m), res;
  rep(i, m) cin >> av[i];
  stack<int> stk;
  for (int i = 0, j = 0; i < n; i++) {
    if (j < m && av[j] - 1 == i) {
      j++;
      stk.push(i + 1);
    } else {
      stk.push(i + 1);
      while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
      }
    }
  }
  rep(i, res.size()) { cout << res[i] << " \n"[i == as_int(res.size()) - 1]; }
  return 0;
}
#endif
