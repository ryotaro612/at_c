#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 100001;

struct Uf {
  vector<int> p;
  Uf(int mx) {
    p = vector<int>(mx);
    for(int i=0;i<mx;i++) {
      p[i] = i;
    }
  };

  int find(int i) {
    if(p[i] == i) {
      return i;
    }
    return p[i] = find(p[i]);
  }

  bool is_same_group(int i, int j) {
    return find(i) == find(j);
  }

  void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    p[root_i] = root_j;
  }
};

int solve(int n, int m, vector<int> p, vector<int> x, vector<int> y) {
  map<int, int> mp;

  for(int i= 0;i<n;i++) {
    mp[p[i]-1] = i;
  }

  Uf uf = Uf(MX);
  for(int i=0;i<m;i++) {
    uf.unite(mp[x[i]-1], mp[y[i]-1]);
  }
  int res = 0;
  for(int i=0;i<n;i++) {
    if(uf.is_same_group(p[i]-1, i))
      res++;
  }
  return res;
}
/*
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n), x(m), y(m);
  for(int i=0;i<n;i++) {
    cin >> p[i];
  }
  for(int i=0;i<m;i++) {
    cin >> x[i] >> y[i];
  }
  cout << solve(n, m, p, x, y);
}
*/
