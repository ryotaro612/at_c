#include <vector>
#include <iostream>
#include <set>
#include "friend_suggestions.h"

using namespace std;
// 人はn人 
// m組の友達関係
// k組のブロック関係
// a, bは友達関係
// c, dはブロック関係
//
//
//

static const int MAX_N = 100001;
int par[MAX_N];
int uf_size[MAX_N];

void init(int n) {
  for(int i=0;i<n;i++) {
    par[i] = i;
    uf_size[i] = 1;
  }
}

int find(int x) {
  if (par[x] == x)
    return x;

  int root = find(par[x]);
  uf_size[x] = uf_size[root];
  return par[x] = root;
}

int group_size(int x) {
  int root = find(x);
  return uf_size[root];
}

void unite(int x, int y) {
  int root_of_x = find(x);
  int root_of_y = find(y);
  if(root_of_x == root_of_y)
    return;

  int united_size = uf_size[root_of_y] + uf_size[root_of_x];
  par[root_of_y] = root_of_x;
  uf_size[root_of_x] = united_size;
}

bool same(int x, int y) {
  return find(x) == find(y);
}

vector<int> friend_suggestions(int n, int m, int k, int a[], int b[], int c[], int d[]) {
  init(n);

  vector<set<int>> friends; 
  vector<set<int>> blocks; 
  for(int i=0;i<n;i++) {
    friends.push_back(set<int>());
    blocks.push_back(set<int>());
  }

  for(int i=0;i<m;i++) {
    int aa = a[i] - 1;
    int bb = b[i] - 1;

    unite(aa, bb);
    friends[aa].insert(bb);
    friends[bb].insert(aa);
  }

  for(int i=0;i<k;i++) {
    int cc = c[i] - 1;
    int dd = d[i] - 1;
    blocks[cc].insert(dd);
    blocks[dd].insert(cc);
  }
  /*
  cout << "Friends group size ======" << endl;
  for(int i=0;i<n;i++) {
    cout << i << " size -> " << group_size(i) << endl;
  }
  cout << "=========================" << endl;
  */
  vector<int> ans;
  for(int i=0;i<n;i++) {

    int num_of_friends_in_group = 0;
    for(auto iter = friends[i].begin(); iter != friends[i].end();iter++) {
      if(same(i, *iter)) {
	  num_of_friends_in_group++;
      }
    }
    // cout << i << " -> direct_friends_num: "  << num_of_friends_in_group << endl;

    int num_of_blocks_in_group = 0;
    for(auto iter = blocks[i].begin(); iter != blocks[i].end();iter++) {
      if(same(i, *iter)) {
	  num_of_blocks_in_group++;
      }
    }
    // cout << i << " -> direct_block_num: "  << num_of_blocks_in_group << endl;
    int g_size = group_size(i);
    ans.push_back(g_size - 1 - num_of_friends_in_group - num_of_blocks_in_group);
  }

  return ans;
}
/*
int main() {
  int n, m, k;
  cin >> n;
  cin >> m;
  cin >> k;

  int a[m], b[m];
  for(int i=0;i<m;i++) {
    cin >> a[i];
    cin >> b[i];
  }

  int c[k], d[k];
  for(int i=0;i<k;i++) {
    cin >> c[i];
    cin >> d[i];
  }

  vector<int> ans = friend_suggestions(n, m, k, a, b, c, d);
  for(int i = 0; i<n;i++) {
    cout << ans[i];
    if(i != n-1) {
      cout << " ";
    }
  }
}
*/
