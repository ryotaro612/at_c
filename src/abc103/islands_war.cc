#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

int islands_war(int n, vector<int> a, vector<int> b) {
  int m = a.size();

  vector<pair<int, int>> ab;

  for (int i=0;i<m;i++) {
    ab.push_back(make_pair(a[i], b[i]));
  }
  sort(ab.begin(), ab.end(), sortbysec);
  
  int ans = 1;
  int cut = ab[0].second -1;
  for(int i=1;i<m;i++) {
    if(ab[i].first<=cut) {
      continue;
    }
    ans++;
    cut = ab[i].second-1;
  }
  
  return ans;
}
/*
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a, b;
  for(int i=0;i<m;i++) {
    int aa, bb;
    cin >> aa >> bb;
    a.push_back(aa);
    b.push_back(bb);
  }
  cout << islands_war(n, a, b);
}
*/
