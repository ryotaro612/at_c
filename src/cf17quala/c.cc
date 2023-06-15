#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
void debug_() { cout << endl; }
template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cout << H << " ";
  debug_(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...) debug_(__VA_ARGS__)
#else
#define debug(...)
#endif

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
  cout << "[";
  string s[2] = {", ", "]"};
  rep(i, v.size()) { cout << v[i] << s[i == int(v.size()) - 1]; }
  return os;
}
int freq[26];
#ifdef ONLINE_JUDGE
int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) { freq[s[j] - 'a']++; }
  }
  int n4 = 0, n2 = 0, odd = 0;
  rep(i, 26) {
    if (freq[i] % 4 == 0)
      n4++;
    else if (freq[i] % 2 == 0)
      n2++;
    else
      odd++;
  }
  if (h % 2 == 0 && w % 2 == 1) {
    swap(h, w);
  }
  if (h % 2) {
    if (w % 2) {
      int two = h / 2 + w / 2;
      if (odd == 1 && two - n2 >= 0 && (two - n2) % 2 == 0)
        cout << "Yes\n";
      else
        cout << "No\n";
      return 0;
    } else {
      if (odd == 0 && w / 2 - n2 >= 0 && (w / 2 - n2) % 2 == 0) {
        cout << "Yes\n";
      } else
        cout << "No\n";
      return 0;
    }
  } else {
    if (odd == 0 && n2 == 0)
      cout << "Yes\n";
    else
      cout << "No\n";
    return 0;
  }

  return 0;
}
#endif
