#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> solve(int n, string &s) {
  deque<int> deq;
  deq.push_back(n);
  for (int i = n - 2; i >= 0; i--) {
    int d = i + 1;
    if (s[i + 1] == 'L') {
      deq.push_back(d);
    } else { // 'R'
      deq.push_front(d);
    }
  }
  if (s[0] == 'L') {
    deq.push_back(0);
  } else {
    deq.push_front(0);
  }
  // zero
  vector<int> res(deq.begin(), deq.end());
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> res = solve(n, s);
  rep(i, n + 1) {
    cout << res[i];
    if (i < n) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  return 0;
}
#endif
