#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

long long various_sushi(int n, int k, int t[], long long d[]) {
  map<int, vector<long long>> mp;  
  for(int i=0;i<n;i++) {
    if(mp.find(t[i]) == mp.end()) {
      vector<long long> m;
      mp[t[i]] = m;
    }
    // cout << "t[i]: " << t[i] << " d[i]: " << d[i] << " size: " << mp[t[i]].size() << endl;
    mp[t[i]].push_back(d[i]);
  }
  vector<long long> max_sushi;
  vector<long long> not_max_sushi;
  for(auto i = mp.begin(); i!= mp.end();i++) {
    vector<long long> v = i->second;
    vector<long long>::iterator max_v = max_element(v.begin(), v.end());
    max_sushi.push_back(*max_v);
    v.erase(max_v);
    for(auto iv = v.begin(); iv != v.end(); iv++) {
      not_max_sushi.push_back(*iv);
    }
  }
  sort(max_sushi.begin(), max_sushi.end(), greater<long long>());
  sort(not_max_sushi.begin(), not_max_sushi.end(), greater<long long>());
  /*
  for(int i=0;i<max_sushi.size();i++) {
    cout << max_sushi[i] << endl;
  }
  cout << "=====" << endl;
  for(int i=0;i<not_max_sushi.size();i++) {
    cout << not_max_sushi[i] << endl;
  }
  */
  vector<long long> sum_max_sushi;
  vector<long long> sum_not_max_sushi;
  for(int i=0;i<max_sushi.size();i++) {
    if(i==0) {
      sum_max_sushi.push_back(max_sushi[i]);
      continue;
    }
    sum_max_sushi.push_back(sum_max_sushi[i-1] + max_sushi[i]);
  }
  for(int i=0;i<not_max_sushi.size();i++) {
    if(i==0) {
      sum_not_max_sushi.push_back(not_max_sushi[i]);
      continue;
    }
    sum_not_max_sushi.push_back(sum_not_max_sushi[i-1] + not_max_sushi[i]);
  }
  /*
  for(int i=0;i<sum_max_sushi.size();i++) {
    cout << sum_max_sushi[i] << endl;
  }
  cout << "=====" << endl;
  for(int i=0;i<sum_not_max_sushi.size();i++) {
    cout << sum_not_max_sushi[i] << endl;
  }
  */

  long long ans=0;

  for(int i=1;i<=k;i++) {
    if(i > sum_max_sushi.size())
      continue;
    long long point = sum_max_sushi[i-1];
    if(i != k) {
        point += sum_not_max_sushi[k-i-1];
    }
    // cout << "i: " << i << " ans: " << point + i*i << endl;
    ans = max(ans, point + i*i);
  }
  return ans;
}
/*
int main() {
  int n, k;
  cin >> n;
  cin >> k;
  int t[n];
  long long d[n];
  for(int i=0;i<n;i++) {
    cin >> t[i];
    cin >> d[i];
  }
  cout << various_sushi(n, k, t, d);
}
*/
