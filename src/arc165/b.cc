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
void write(vector<int> &pv) {
  rep(i, pv.size()) cout << pv[i] << " \n"[i == (int)pv.size() - 1];
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> pv(n);
  rep(i, n) cin >> pv[i];
  if (k == 1) {
    write(pv);
    return 0;
  }
  int count = 0;
  rep(i, n - 1) {
    if (pv[i] < pv[i + 1])
      count++;
    if (i >= k - 1) {
      if (pv[i - (k - 1)] < pv[i - (k - 1) + 1])
        count--;
    }
    if (count == k - 1) {
      write(pv);
      return 0;
    }
  }

  vector<int> cand(pv);
  sort(begin(cand) + n - k, end(cand));

  int i = n - k;
  while (i && pv[i - 1] < pv[i])
    i--;
  set<int> later(begin(pv) + n - k, begin(pv) + i + k - 1);
  while(i<n-k) {
    if(*begin(later) > pv[n-k-1]) {
      sort(begin(pv) + i, begin(pv) +i + k);
      if(pv > cand)
	write(pv);
      else
	write(cand);
      return 0;
    } else {
      later.insert(pv[i+k-1]);
      i++;
    }
  }
  write(cand);
  return 0;
}
