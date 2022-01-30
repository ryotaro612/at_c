#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool is_all_a(string &s) {
  for (auto &c : s) {
    if (c != 'a') {
      return false;
    }
  }
  return true;
}

bool kaibun(string s) {
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) {
      return false;
    }
  }
  return true;
}

string solve(string &s) {
  int n = s.size();
  if (is_all_a(s)) {
    return "Yes";
  }
  int left = 0;
  // cout << "left: " << left << endl;
  while (s[left] == 'a') {
    left++;
  }
  int right = n;
  while (s[right - 1] == 'a') {
    right--;
  }
  // cout << "right: " << right << endl;
  string sub = string(s.begin() + left, s.begin() + right);
  if (!kaibun(sub)) {
    return "No";
  }
  //  cout << "sub: " << sub << endl;
  if (left <= n - right) {
    return "Yes";
  } else {
    return "No";
  }
}

#ifdef ONLINE_JUDGE
int main() {
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}
#endif
