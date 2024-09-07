#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)														\
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__ \
  << " = ";																\
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
  int n;
  cin >> n;
  vector<vector<int>> am(n);
  rep(i, n) {
	am[i] = vector<int>(i+1);
	rep(j, i+1) {
	  cin >> am[i][j];
	  am[i][j]--;
	}
  }
  int res  = 0;

  rep(i, n) {
	if(res >= i) {
	  res = am[res][i];
	} else {
	  res = am[i][res];
	}
  }
  cout << res + 1 << endl;
  return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using ld = long double;
// using ull = unsigned long long;
// #define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #ifndef ONLINE_JUDGE
// #define dbg(...)														\
//   cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__ \
//   << " = ";																\
//   debug_(__VA_ARGS__);
// #else
// #define dbg(...)
// #endif
// template <typename Os, typename... Ts>
// Os &operator<<(Os &os, const pair<Ts...> &p) {
//   return os << "{" << p.first << ", " << p.second << "}";
// }
// template <typename Os, typename T>
// typename enable_if<is_same<Os, ostream>::value, Os &>::type
// operator<<(Os &os, const T &v) {
//   os << "[";
//   string sep = "";
//   for (auto &x : v) {
//     os << sep << x;
//     sep = ", ";
//   };
//   return os << "]";
// }

// void debug_() { cerr << "\e[39m" << endl; }

// template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
//   cerr << H << " ";
//   debug_(T...);
// }
// int main() {
//   int n;
//   cin >> n;
//   vector<vector<int>> am(n+1);
//   for(int i = 1; i<=n;i++) {
// 	am[i] = vector<int>(i);
// 	for(int j=1;j< i+1;j++) {
// 	  cin >> am[i][j];
// 	}
//   }
//   int res  = 1;

//   for(int i=1;i<=n;i++) {
// 	if(res >= i) {
// 	  res = am[res][i];
// 	} else {
// 	  res = am[i][res];
// 	}
//   }
//   cout << res << endl;
//   return 0;
// }
