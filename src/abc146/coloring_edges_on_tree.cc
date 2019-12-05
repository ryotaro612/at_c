#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
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
  int color_num = 0;  
  queue<int> que;
  map<pair<int, int>, int> mp;
  que.push(0);
  vector<int> ans;
  while(!que.empty()) {
    int vertex = que.front();
    vector<int> vertex_vec = graph[vertex];
    int degree = vertex_vec.size();
    color_num = color_num > degree ? color_num : degree;

    for(int i=0; i< vertex_vec.size(); i++){
      int vertex2 = vertex_vec[i];
      make_pair(_T1 &&__t1, _T2 &&__t2)
    }

    que.pop();
  }

  return ans;
}
