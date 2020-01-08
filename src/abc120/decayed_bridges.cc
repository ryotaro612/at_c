#include <iostream>
#include <algorithm>
#include <vector>
#include "decayed_bridges.h"
#define MAX_N 100000
using namespace std;

long long par[MAX_N];
int size[MAX_N];

void init(long long n) {
  for(int i=0;i<n;i++) {
    par[i] = i;
    size[i] = 1;
  }
}

// rootを返す
long long find(long long x) {
  if(par[x] == x) {
    return x;
  }
  long long root = find(par[x]);
  par[x] = root;
  return root;
}

void unite(long long x, long long y) {
  // 親どうし
  long long root_x = find(x);
  long long root_y = find(y);
  if (root_x == root_y) {
    return;
  }
  par[root_y] = root_x;
  size[root_x] += size[root_y];
}

bool same(long long x, long long y) {
  return find(x) == find(y);
}

long long size_tree(long long x) {
  return size[find(x)];
}
/*
 * n 島の数 
 * m 橋の数
 * a[i] - b[i];
 */
vector<long long> decayed_bridges(long long n, long long m, long long a[], long long b[]) {
  init(n);
  vector<long long> answer;
  answer.push_back((n * (n-1)) / 2);
  for(int i=m-1;i>=1;i--) {
    int aa = a[i] - 1;
    int bb = b[i] - 1;
    long long last = answer[answer.size() - 1];
    if(same(aa, bb)) {
      answer.push_back(last);
      continue;
    }
    answer.push_back(last - size_tree(aa) * size_tree(bb));
    unite(aa, bb);
  }
  reverse(answer.begin(), answer.end());
  return answer;
}

/*
int main() {
  long long n, m;
  cin >> n;
  cin >> m;
  long long a[m];
  long long b[m];
  for(int i=0;i<m;i++) {
    cin >> a[i];
    cin >> b[i];
  }
  vector<long long> answer = decayed_bridges(n, m, a, b);
  for(int i=0;i<answer.size();i++) {
    cout << answer[i];
    if(i != answer.size())
      cout << endl;
  }
}
*/
