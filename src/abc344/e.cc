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

struct Node {
  shared_ptr<Node> prev, next;
  ll v;
  Node(shared_ptr<Node> prev, shared_ptr<Node> next, ll v) : prev(prev), next(next), v(v) {}  
  Node(ll v) : prev(nullptr), next(nullptr), v(v) {}
  Node() : prev(nullptr), next(nullptr), v(0) {}
};

void aaa(shared_ptr<Node> sentinel) {
  shared_ptr<Node> cur = sentinel->next;
  vector<ll> res;
  while (cur != nullptr) {
    res.push_back(cur->v);
    cur = cur->next;
  }
  dbg(res);
}
int main() {
  int n, q;
  cin >> n;
  shared_ptr<Node> sentinel = shared_ptr<Node>(new Node());
  shared_ptr<Node> cur = sentinel;
  map<ll, shared_ptr<Node>> mp;
  rep(_, n) {
    ll a;
    cin >> a;
    cur->next = shared_ptr<Node>(new Node(cur, nullptr, a));
    cur = cur->next;
    mp[a] = cur;
  }
  cin >> q;
  rep(_, q) {
    ll t, x;
    cin >> t >> x;
    if (t == 1) {
      ll y;
      cin >> y;
      shared_ptr<Node> a = mp[x]->next;
      shared_ptr<Node> node = shared_ptr<Node>(new Node(mp[x], mp[x]->next, y));
      if(a != nullptr) {
	a->prev = node;
      }
      mp[x]->next = node;
      mp[y] = node;
      dbg("t1", x, y);

    } else {
      shared_ptr<Node> node = mp[x];
      node->prev->next = node->next;
      if(node->next != nullptr) {
	node->next->prev = node->prev;
      }
      node->next = node->prev = nullptr;
      mp.erase(x);
      dbg("t2", x);

    }
  }
  cur = sentinel->next;
  vector<ll> res;
  while (cur != nullptr) {
    res.push_back(cur->v);
    cur = cur->next;
  }
  rep(i, res.size()) { cout << res[i] << " \n"[i == (int)res.size() - 1]; }
  return 0;
}
