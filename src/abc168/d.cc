#include<bits/stdc++.h>
typedef int ll;
using namespace std;

static const ll INF = -1;
vector<ll> abc168d(ll n, vector<vector<ll>> edge) {
  vector<ll> d(n, INF);

  queue<ll> que;
  que.push(0);
  d[0] = 0;

  vector<ll> ans(n-1);
  while(!que.empty()) {
    ll v = que.front();
    que.pop();
    for(auto nv: edge[v]) {
      if(d[nv] == INF) {
	d[nv] = d[v] + 1;
	ans[nv-1] = v + 1;
	que.push(nv);
      }
    }
  }
  return ans;
}
/*
int main() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> edge;
  edge.assign(n, vector<ll>());

  for(ll i=0;i<m; i++) {
    ll a, b;
    cin >> a >> b; 
    edge[a-1].push_back(b-1);
    edge[b-1].push_back(a-1);
  }

  vector<ll> ans = abc168d(n, m, edge);
  cout << "Yes" << endl;
  for(ll i=0; i < n-1; i++) {
    cout << ans[i];
    if(i != n-2) {
      cout << endl;
    }
  }
}
*/
