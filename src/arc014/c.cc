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

#ifdef ONLINE_JUDGE
int main() {
  int n;
  string s;
  cin >> n >> s;
  stack<char> stk;
  for (char c : s) {
    if (stk.empty())
      stk.push(c);
    else {
      if (c == stk.top())
        stk.pop();
      else
        stk.push(c);
    }
  }
  string temp;
  while (!stk.empty()) {
    temp.push_back(stk.top());
    stk.pop();
  }
  reverse(temp.begin(), temp.end());
  deque<char> que;
  // cout << temp << endl;
  rep(i, temp.size()) {
    // cout << i << endl;
    if (que.size() == 0) {
      que.push_back(temp[i]);
    } else if (que.size() == 1) {
      if (que.front() == temp[i])
        que.pop_front();
      else
        que.push_back(temp[i]);
    } else {
      if (temp[i] == que.front())
        que.pop_front();
      else if (temp[i] == que.back())
        que.pop_back();
      else {
        if (i < as_int(temp.size()) - 1) {
          if (que.front() == temp[i + 1])
            que.push_back(temp[i]);
          else
            que.push_front(temp[i]);
        } else {
          que.push_front(temp[i]);
        }
      }
    }
  }
  cout << que.size() << endl;
  return 0;
}
#endif
