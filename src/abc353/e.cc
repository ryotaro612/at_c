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

class TrieNode {
public:
  TrieNode(char c);

private:
  map<char, TrieNode> children;
  optional<char> _c = nullopt;
  int freq = 0;
};

TrieNode::TrieNode(char c) { _c = c; }

void put(string &s, map<char, map<char, int>> &trie) {

  for (auto c : s) {
  }
}

class Trie {
public:
  void put(string &s) {

    int cur = 0;
    trie[0].first += 1;
    for (auto c : s) {
      if (!trie[cur].second.contains(c)) {
        trie[cur].second[c] = trie.size();
        trie.push_back({0, map<char, int>()});
      }
      cur = trie[cur].second[c];
      trie[cur].first += 1;
    }
  }

  ll count(string &s) {
    ll res = 0;
    auto cur = 0;
    for (auto c : s) {
      if (!trie[cur].second.contains(c))
        break;
      cur = trie[cur].second[c];
      res += trie[cur].first;
    }
    return res;
  }

private:
  vector<pair<ll, map<char, int>>> trie = {{0, map<char, int>()}};
};

int main() {
  int n;
  cin >> n;
  vector<string> sv(n);
  rep(i, n) cin >> sv[i];
  ll res = 0;
  Trie trie;
  for (int i = sv.size() - 1; i >= 0; i--) {
    res += trie.count(sv[i]);
    trie.put(sv[i]);
  }
  cout << res << endl;
  return 0;
}
