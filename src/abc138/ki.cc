#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;


std::vector<int> ki(int n, int q, int a[], int b[], int p[], int x[]) {
  map<int, set<int>> tree; 
  for(int i =0;i<n-1;i++) {
    tree[a[i]].insert(b[i]);
    tree[b[i]].insert(a[i]);
  }
  map<int, int> points; 
  for(int i=0;i<q;i++) {
    points[p[i]] += x[i];
  }
  queue<int> que;
  que.push(1);
  vector<int> ans(n);
  while(!que.empty()) {
    int parent = que.front();
    que.pop();
    ans[parent-1] += points[parent];
    set<int> nodes = tree[parent];
    for(auto node = nodes.begin();node!=nodes.end(); node++) {
      tree[*node].erase(parent);
      que.push(*node);
      ans[(*node) - 1] = ans[parent-1];
    }
  }
  return ans;
}
/*
int main() {
  int n, q;
  cin >> n >> q;
  int a[n-1];
  int b[n-1];
  int p[q];
  int x[q];
  for(int i=1;i<=n-1;i++) {
    cin >> a[i-1] >> b[i-1];
  }
  for(int i=0;i<q;i++) {
    cin >> p[i] >> x[i];
  }
  vector<int> ans = ki(n, q, a, b, p, x);
  int size = (int) ans.size();
  for(int i=0;i<size;i++) {
    cout << ans[i];

    if(i != size - 1) {
      cout << " ";
    } 
  }
}
*/
