#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;

vector<int> coloring_edges_on_tree(int n, int a[], int b[]) {
  vector<vector<int>> graph;
  for(int i=0;i<n;i++) {
    int vertex_a = a[i] - 1;
    int vertex_b = b[i] - 1;
    graph[vertex_a].push_back(vertex_b);
    graph[vertex_b].push_back(vertex_a);
  }
  int color_num = INT_MAX;  
  queue<int> que;
  que.push(0);
  // 色の最大はn以下
  vector<int> ans;
  while(!que.empty()) {
    int vertex = que.front();
    que.pop();
  }
  set<int> a{1, 2};
  map<set<int>, int> mp;


  return ans;
}
