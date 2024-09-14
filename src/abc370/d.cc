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
int main() {
  int h, w, q;
  cin >> h >> w >> q;
  vector<set<int>> hv(h), wv(w);
  rep(i, h) {
    rep(j, w) {
      hv[i].insert(j);
      wv[j].insert(i);
    }
  }

  rep(_, q) {
    int r, c;
    cin >> r >> c;
	r--;
	c--;
	dbg("doge");
	if(hv[r].contains(c)) {
	  hv[r].erase(c);
	  wv[c].erase(r);
	  continue;
	}
	dbg("doge1");
	auto up_iter = wv[c].lower_bound(r);
	int up = -1, down = -1;
	if(up_iter != begin(wv[c])) {
	  up = *prev(up_iter);
	}
	if(up_iter != end(wv[c])) {
	  down = *up_iter;
	}
	if(up != -1) {
	  wv[c].erase(up);
	  hv[up].erase(c);
	  dbg("remove", up, c);
	}	
	if(down != -1) {
	  wv[c].erase(down);
	  hv[down].erase(c);
	  dbg("remove", down, c);	  
	}
	auto right_iter = hv[r].lower_bound(c);
	int right = -1, left = -1;
	if(right_iter != begin(hv[r])) {
	   left = *prev(right_iter);	  
	}
	if(right_iter != end(hv[r])) {
	  right = *right_iter;
	}
   
	if(left != -1) {
	  hv[r].erase(left);
	  wv[left].erase(r);
	  dbg("remove", r, left);	  	  
	}
	
	if(right != -1) {
	  hv[r].erase(right);
	  wv[right].erase(r);
	  dbg("remove", c, right);	  	  	  
	}
  }
  int res = 0;
  rep(i, h){
	rep(j, w) {
	  if(hv[i].contains(j))
		res++;
	}
  }
  cout << res << endl;
  return 0;
}
