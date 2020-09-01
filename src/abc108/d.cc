#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class I {
  public:
    ll u, v, w;

    I(ll uu, ll vv, ll ww) {
      u = uu;
      v = vv;
      w = ww;
    }
};

class A {
  public:
    int n, m;
    vector<I> edges; 
    A(int nn, int mm, vector<I> e) {
      n = nn;
      m = mm;
      edges = e;
    }
};

A d(ll l) {
  int n = 2;
  vector<I> edges;

  while(true) {
    if(pow(2, n-1) <= l && l < pow(2, n)) {
      break;
    } 
    n++;
  }

  for(int i =1;i<n;i++) {
    I e(i, i+1, pow(2, i-1));
    edges.push_back(e);
    I e0(i, i+1, 0);
    edges.push_back(e0);
  }
  if(pow(2, n-1) == l) {
    return A(n, edges.size(), edges);
  }
  ll remain = l-1;
  ll offset = pow(2, n-1) -1;
  for(int i=n-2; i>=0; i--) {
    if(offset + pow(2, i) <= remain) {
      I e(i+1, n, remain - pow(2, i) + 1);
      remain -= pow(2, i);
      edges.push_back(e);
    }
  }

  return A(n, edges.size(), edges);
}
/*
int main() {
  ll l;
  cin >> l;
  A a = d(l);
  cout << a.n << " " << a.m << endl;
  for(auto e: a.edges) {
    cout << e.u << " " << e.v << " " << e.w << endl;
  }
}
*/
