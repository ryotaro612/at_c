#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<iostream>
 
using namespace std;
 
vector<int> double_dots(int n, int m, int a[], int b[]) {
  map<int, vector<int>> mp;
  for(int i=0;i<m;i++) {
    vector<int> arr = mp[a[i]];
    arr.push_back(b[i]);
    mp[a[i]] = arr;
    arr = mp[b[i]];
    arr.push_back(a[i]);
    mp[b[i]] = arr;
  }
  queue<int> que;
  /*
  for(auto i = mp.begin(); i != mp.end() ; ++i) {
      std::cout << i->first << " " << (i->second).size() << "\n";
  }
  */
  vector<int> ans;
  vector<bool> gone;
  vector<int> points;
  int inf = 100001;
  for(int i=0;i<n;i++) {
    ans.push_back(inf);
    gone.push_back(false);
    points.push_back(-1);
  }
  que.push(0);
  ans[0] = 0;
  while(!que.empty()) {
    int room = que.front();
    vector<int> neigh = mp[room];
    for(int i=0;i<neigh.size();i++) {
      int neigh_item = neigh[i];
      if(ans[room] + 1 < ans[neigh_item]) {
	ans[neigh_item] = ans[room] + 1;
	points[neigh_item] = room;
      }
      if(gone[neigh_item] == false) {
	que.push(neigh_item);
      }
    }
    gone[room] = true;
    que.pop();
  }
  /*
  vector<int> rtn;
  for(int i=1;i<n;i++) {
    rtn.push_back(points[i] + 1);
  }
  */
  return points;
}
/* 
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  int a[m];
  int b[m];
  for(int i=0;i<m;i++) {
    int aa;
    int bb;
    cin >> aa;
    cin >> bb;
    a[i] = aa - 1;
    b[i] = bb - 1;
  }
  vector<int> ans = double_dots(n, m, a, b);
  cout << "Yes" << endl;
  for(int i=1; i < ans.size(); i++) {
    cout << ans[i] + 1;
    if(i != ans.size() -1) {
      cout << endl;
    }
  }
}
*/
