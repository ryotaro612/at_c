#include<iostream>
#include<vector>
#include "at_coder_express2.h"
using namespace std;

vector<long long> at_coder_express2(int n, int m, int q, vector<std::pair<int, int>> lr,vector<pair<int, int>> pq) {
  int mat[501][501];
  long long mul[501][501];
  for(int rr=0;rr<501;rr++) {
    for(int ll=0;ll<501;ll++){
      mat[rr][ll] = 0;
      mul[rr][ll] = 0;
    }
  }

  for(auto iter=lr.begin();iter != lr.end(); iter++) {
    mat[(*iter).first][(*iter).second]++;
  }
  for(int ll = 1; ll < 501;ll++) {
    for(int rr=1;rr<501;rr++) {
      mul[ll][rr] = mul[ll][rr-1] + mat[ll][rr];
    }
  }
  vector<long long> ans;
  for(int i=0;i<q;i++) {
    pair<int, int> pq_i = pq[i];
    long long a = 0;
    for(int j = pq_i.first; j <= pq_i.second; j++) {
      a += mul[j][pq_i.second] - mul[j][pq_i.first-1];
    }
    ans.push_back(a);
  }
  return ans;
}
/*
int main() {
  int n, m, q;
  cin >> n;
  cin >> m;
  cin >> q;
  vector<pair<int, int>> lr;
  for(long long i=0LL;i<m;i++) {
    int l, r;
    cin >> l;
    cin >> r;
    lr.push_back(make_pair(l, r));
  }
  vector<pair<int, int>> pq;
  for(long long i=0LL;i<q;i++) {
    int l, r;
    cin >> l;
    cin >> r;
    pq.push_back(make_pair(l, r));
  }
  vector<long long> ans = at_coder_express2(n, m, q, lr, pq);
  for(long long i=0;i<ans.size();i++) {
    cout << ans[i];
    if(i != ans.size() - 1)
      cout << endl;
  }
}
*/
