#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static long long west = -60000000000;
static long long east =  60000000000;

long long dist(long long a, long long b, long long x) {
  return abs(x - a) + abs(a - b);
}

vector<long long> lazy_faith(
    long long a, 
    long long b,
    long long q,
    long long s[], 
    long long t[], 
    long long x[]) {
  vector<long long> ans;
  vector<long long> ss;
  
  ss.push_back(west);
  for(int i=0;i<a;i++) {
    ss.push_back(s[i]);
  }
  ss.push_back(east);
  
  vector<long long> tt;
  tt.push_back(west);
  for(int i=0;i<b;i++) {
    tt.push_back(t[i]);
  }
  tt.push_back(east);

  for(int i=0;i<q;i++) {
    long long xx = x[i];

    auto it = lower_bound(ss.begin(), ss.end(), xx);
    long long sa = ss[distance(ss.begin(), it) -1];

    it = upper_bound(ss.begin(), ss.end(), xx);
    long long sb = ss[distance(ss.begin(), it)];

    it = lower_bound(tt.begin(), tt.end(), xx);
    long long ta = tt[distance(tt.begin(), it) -1];

    it = upper_bound(tt.begin(), tt.end(), xx);
    long long tb = tt[distance(tt.begin(), it)];

    long long result = min(dist(sa, ta, xx), dist(sb, ta, xx));
    result = min(result, dist(ta, sa, xx));
    result = min(result, dist(tb, sa, xx));
    result = min(result, dist(sa, tb, xx));
    result = min(result, dist(sb, tb, xx));
    result = min(result, dist(ta, sb, xx));
    result = min(result, dist(tb, sb, xx));
    ans.push_back(result);
  }
  return ans;
}
/*
int main() {
  long long a, b, q;
  cin >> a;
  cin >> b;
  cin >> q;
  long long s[a];
  long long t[b];
  long long x[q];
  for(int i=0;i<a;i++) {
    cin >> s[i];
  }
  for(int i=0;i<b;i++) {
    cin >> t[i];
  }
  for(int i=0;i<q;i++) {
    cin >> x[i];
  }
  vector<long long> ans = lazy_faith(a, b, q, s, t, x);
  for(int i=0;i< ans.size();i++) {
    cout << ans[i];
    if(i-1 != ans.size()) {
      cout << endl;
    }
  }
}
*/
