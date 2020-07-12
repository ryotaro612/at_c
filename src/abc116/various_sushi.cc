#include<iostream>
#include<map>
#include<unordered_set>
#include<utility>
#include<set>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


long long various_sushi(long long n, long long k, long long t[], long long d[]) {
  priority_queue<pair<long long, long long>> oishisa_que;
  for(long long i =0;i<n;i++) {
    oishisa_que.push(make_pair(d[i], t[i]));
  }
  map<long long, bool> sushi_base_map;

  long long base_point =0;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> chosen_que;

  for(long long i=0;i<k;i++) {
    pair<long long, long long> sushi_d = oishisa_que.top();
    oishisa_que.pop();
    base_point += sushi_d.first;
    if(!sushi_base_map[sushi_d.second]) {
      // new
      sushi_base_map[sushi_d.second] = true;
      continue;
    }
    // existing
    chosen_que.push(sushi_d);
  }
  long long max_total_point = base_point + (sushi_base_map.size() * sushi_base_map.size());
  while(!oishisa_que.empty() && !chosen_que.empty()) {
    pair<long long, long long> sushi_d = oishisa_que.top();
    oishisa_que.pop();
    pair<long long, long long> min_sushi_d = chosen_que.top();
    chosen_que.pop();
    base_point -= min_sushi_d.first;
    base_point += sushi_d.first;

    if(!sushi_base_map[sushi_d.second]) {
      sushi_base_map[sushi_d.second] = true;
    } else {
      chosen_que.push(sushi_d);
    }
    long long siz = (long long) (sushi_base_map.size() * sushi_base_map.size());
    max_total_point = max(base_point + siz, max_total_point);
  }

  return max_total_point;
}
/*
     int main() {
     long long n, k;
     cin >> n;
     cin >> k;
     long long t[n];
     long long d[n];
     for(int i=0;i<n;i++) {
     cin >> t[i];
     cin >> d[i];
     }
     cout << various_sushi(n, k, t, d);
     }
     */
