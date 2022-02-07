#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<string> wv(n);
  rep(i, n) cin >> wv[i];
  unordered_set<string> st(wv.begin(), wv.end());
  if (wv.size() != st.size()) {
    cout << "No" << endl;
    return 0;
  }
  char c = wv[0].back();
  for (int i = 1; i < n; i++) {
    if (c != wv[i][0]) {
      cout << "No" << endl;
      return 0;
    }
    c = wv[i].back();
  }
  cout << "Yes" << endl;
  return 0;
}
#endif
