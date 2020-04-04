#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;

vector<long long> banned_k(vector<int> a) {
  map<long long, long long> mp;
  
  for(auto iter = a.begin(); iter != a.end(); iter++) {
    int aa = *iter;
    int current = mp[aa];
    mp[aa] = current+1;
  }

  long long all = 0;
  for(auto iter = mp.begin(); iter != mp.end(); iter++) {
    //cout << iter->first << " -> " << iter->second << endl;
    all += ((iter->second)*((iter->second) -1))/2;
  }

  vector<long long> ans;
  for(auto iter = a.begin(); iter != a.end(); iter++) {
    ans.push_back(all - (mp[(*iter)] - 1));
  }

  return ans;
}
/*
int main() {
  int n;
  cin >> n;
  vector<int> a;
  for(int i=0;i<n;i++) {
    int aa;
    cin >> aa;
    a.push_back(aa);
  }
  vector<long long> ans = banned_k(a);
  for(int i=0; i<n;i++) {
    cout << ans[i];
    if(i != n-1) {
      cout << endl;
    }
  }
}
*/
