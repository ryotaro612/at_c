#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Ball {
  int number, count;
};

vector<int> solve(int n, vector<int> &av) {
  stack<Ball> stk;
  vector<int> res;
  for (auto a : av) {
    if (stk.empty()) {
      Ball ball = {a, 1};
      stk.push(ball);
      res.push_back(1);
    } else {
      Ball ball = stk.top();
      if (ball.number != a) {
        stk.push({a, 1});
        res.push_back(res.back() + 1);
      } else { //同じ数
        stk.pop();
        ball = {ball.number, ball.count + 1};
        int delta = 1;
        stk.push(ball);
        while (true) {
          if (stk.empty())
            break;
          Ball topball = stk.top();
          if (topball.count < topball.number)
            break;
          // number <= count
          delta -= topball.number;
          stk.pop();
        }
        res.push_back(res.back() + delta);
      }
    }
  }
  return res;
}

#ifdef ONLINE_JUDGE
int main() {
  int n;
  cin >> n;
  vector<int> av(n);
  rep(i, n) cin >> av[i];
  vector<int> res = solve(n, av);
  for (auto e : res)
    cout << e << endl;
  return 0;
}
#endif
