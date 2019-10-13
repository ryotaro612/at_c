#include <iostream>
#include <vector>
#include <map>
#include "ki.h"

using namespace std;


void dig(map<int, vector<int>> tree, map<int, int> *ans_map, int counter[], int debt, int point) {
  vector<int> children = tree[point];
  (*ans_map)[point] += debt + counter[point];
  for(auto iter = children.begin(); iter != children.end(); iter++) {
    dig(tree, ans_map, counter, debt+counter[point], *iter);
  }
}

std::vector<int> ki(int n, int q, int a[], int b[], int p[], int x[]) {
  map<int, vector<int>> tree;
  int counter[q];
  for (int i=0;i<n-1;i++) {
    tree[a[i]-1].push_back(b[i]-1);
  }
  for(int i=0;i<n;i++)
    counter[i] = 0;

  for(int i=0;i<q;i++) {
    counter[p[i]-1] += x[i];
  }
  
  map<int, int> ans_map;
  dig(tree, &ans_map, counter, 0, 0);

  vector<int> ans;

  for(int i = 0;i<n;i++) {
    ans.push_back(ans_map[i]);
  }
  return ans;
}
