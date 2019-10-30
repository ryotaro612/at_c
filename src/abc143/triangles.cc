#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm> 

using namespace std;

int triangles(int n, int l[]) {
  vector<int> edges;
  for(int i = 0; i<n;i++) {
    edges.push_back(l[i]);
  }
  sort(edges.begin(), edges.end());
  int ans = 0;
  for(int i = edges.size() - 1; i > 0; i--) {
    for(int j = i - 1; j >= 0; j--) {
      // precondition: a>=b>=c;
      int a = edges.at(i);
      int b = edges.at(j);
      vector<int>::iterator c_iter = upper_bound(edges.begin(), edges.end(), a - b);
      int index_c = c_iter - edges.begin();
      if(index_c >= j) {
	continue;
      }
      ans += j - index_c;
    }
  }
  return ans;
}
