#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define as_int(a) static_cast<int>(a)

class Node {
public:
  map<char, Node *> trie;
  int num = 0;
  Node() {}
  Node *get(char c) {
    if (trie.find(c) == trie.end()) {
      trie[c] = new Node();
      return trie[c];
    } else {
      return trie[c];
    }
  }
};

void add(Node &root, string &s) {
  Node *node = &root;
  node->num++;
  for (char &c : s) {
    node = node->get(c);
    node->num++;
  }
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<string> sv(n);
  Node root;
  rep(i, n) {
    cin >> sv[i];
    add(root, sv[i]);
  }
  rep(i, n) {
    Node *node = &root;
    int res = 0;
    for (auto &c : sv[i]) {
      node = node->get(c);
      if (node->num > 1)
        res++;
      else
        break;
    }
    cout << res << endl;
  }
  return 0;
}
#endif
