#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> ans;
vector<vector<pair<int, long long>>> graph;

void dfs(int p, long long cost) {
  for(int i=0;i<graph[p].size();i++) { // !!
    if(ans[graph[p][i].first] != -1) {
      continue;
    }
    long long c_cost = graph[p][i].second + cost;
    ans[graph[p][i].first] = c_cost % 2 == 0 ? 0 : 1;
    dfs(graph[p][i].first, c_cost);
  }
}

vector<int> even_relation(int n, int u[], int v[], long long w[]) {
  for(int i=0;i<n;i++) {
    vector<pair<int, long long>> nodes; 
    graph.push_back(nodes);
    ans.push_back(-1);
  }
  for(int i=0;i<n-1;i++) {
    graph[v[i]-1].push_back(make_pair(u[i]-1, w[i]));
    graph[u[i]-1].push_back(make_pair(v[i]-1, w[i]));
  }
  ans[0] = 0;
  dfs(0, 0);
  return ans;
}
/*
int main(){
  int n;
  cin >> n; 
  int u[n-1];
  int v[n-1];
  long long w[n-1];
  for(int i=0;i<n-1;i++) {
    cin >> u[i];
    cin >> v[i];
    cin >> w[i];
  }
  vector<int> ans = even_relation(n, u, v, w);
  for(int i=0;i<ans.size();i++) {
    if(i != 0)
      cout << endl; 
    cout << ans[i];
  }
}
*/
