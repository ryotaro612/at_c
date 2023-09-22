#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__       \
       << " = ";                                                               \
  debug_(__VA_ARGS__);
#else
#define dbg(...)
#endif
template <typename Os, typename... Ts>
Os &operator<<(Os &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Os, typename T>
typename enable_if<is_same<Os, ostream>::value, Os &>::type
operator<<(Os &os, const T &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

void debug_() { cerr << "\e[39m" << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cerr << H << " ";
  debug_(T...);
}

vector<string> sub(vector<int> &cur, int k, vector<vector<int>> &vv,
                   vector<string> &wv) {
  if ((int)cur.size() == k) {
    rep(i, wv.size()) {
      int count = 0;
      for (auto j : vv[i])
        count += cur[j];

      if (count != (int)wv[i].size())
        return vector<string>();
    }
    vector<string> cand(k, "");
    dbg(cur);
    rep(i, wv.size()) {
      vector<string> chunks(vv[i].size());
      for (int v_i = 0, w_i = 0; v_i < (int)vv[i].size(); v_i++) {
        chunks[v_i] =
            string(begin(wv[i]) + w_i, begin(wv[i]) + w_i + cur[vv[i][v_i]]);
        w_i += cur[vv[i][v_i]];
      }
      dbg(wv[i], chunks);
      rep(j, vv[i].size()) {
        if (cand[vv[i][j]] == "")
          cand[vv[i][j]] = chunks[j];
        else if (cand[vv[i][j]] != chunks[j])
          return vector<string>();
      }
    }
    return cand;
  }

  for (int i = 1; i <= 3; i++) {
    cur.push_back(i);
    vector<string> res = sub(cur, k, vv, wv);
    if ((int)res.size() == k)
      return res;
    cur.pop_back();
  }
  return vector<string>();
}
int main() {
  int k, n;
  cin >> k >> n;
  vector<vector<int>> vv(n);
  vector<string> wv(n);
  rep(i, n) {
    string s;
    cin >> s;
    vv[i] = vector<int>(s.size());
    rep(j, s.size()) vv[i][j] = s[j] - '0' - 1;
    cin >> s;
    wv[i] = s;
    // dbg(vv[i], wv[i]);
  }
  vector<int> cur;
  vector<string> res = sub(cur, k, vv, wv);
  for (auto &s : res)
    cout << s << endl;
  return 0;
}
