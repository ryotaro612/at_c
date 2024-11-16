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
void traverse(int &res, vector<string> &grid, int r, int c, int k) {

  if (k == 0) {
    res++;
    return;
  }
  int h = grid.size();
  int w = grid[0].size();
  vector<pair<int, int>> d = {{r-1, c}, {r, c+1}, {r+1, c}, {r, c-1}};
  for(auto [n_r, n_c]: d) {
	if(0 <= n_r && n_r < h && 0 <= n_c && n_c < w && grid[n_r][n_c] == '.') {
	  grid[n_r][n_c] = '#';
	  traverse(res, grid, n_r, n_c, k-1);
	  grid[n_r][n_c] = '.';
	  	  
	}
  }

}
int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> grid(h);
  rep(i, h) { cin >> grid[i]; }
  int res = 0;
  rep(r, h) {
    rep(c, w) {
      if (grid[r][c] == '.') {
		grid[r][c] = '#';		
		traverse(res, grid, r,  c,  k);
		grid[r][c] = '.';		
      }
    }
  }

  cout << res << endl;
  return 0;
}
