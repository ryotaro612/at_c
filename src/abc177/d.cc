#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mx = 200001;

int u[mx];

int find(int child) {
  int parent = u[child];
  if(child==parent) {
    return parent;
  }
  return u[child] = find(parent);
}

void unite(int c, int d) {
  int root_c = find(c);
  int root_d = find(d);
  if(root_d == root_c) {
    return;
  }

  u[root_c] = root_d;
  return;
}

bool is_same_unit(int a, int b) {
  return find(a) == find(b);
}

ll d(int n, int m, vector<int> a, vector<int> b) {

  for(int i=0;i<n;i++) {
    u[i] = i;
  }
  for(int i=0;i<m;i++) {
    int aa = a[i] - 1;
    int bb = b[i] - 1;
    if(!is_same_unit(aa, bb)) {
      unite(aa, bb);
    }
  }

  map<int, int> cnt;
  for(int i=0;i<n;i++) {
    cnt[find(i)] += 1;
  }
  ll ans = -1;
  for(auto item: cnt) {
    ans = max(ans, (ll) item.second);
  }
  return ans;
}
/*
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);

  for(int i=0;i<m;i++) {
    cin >> a[i] >> b[i];
  }
  cout << d(n, m, a, b);
}
*/
