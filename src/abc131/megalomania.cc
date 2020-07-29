#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
typedef long long ll;

using namespace std;

std::string megalomania(std::vector<ll> a, std::vector<ll> b) {
  using Pair  = std::pair<ll, ll>;
  vector<Pair> works;
  for(ll i = 0;i<a.size();i++) {
    works.push_back(Pair(b.at(i), a.at(i)));
  }
  sort(works.begin(), works.end());

  ll consumption = 0;
  
  for(ll i =0;i<works.size();i++) {
    ll estimation = works.at(i).second;
    ll limit = works.at(i).first;
    consumption += estimation;
    if(consumption > limit) {
      return "No";      
    }
  }
  
  return "Yes";
}
/*
int main() {
  ll n;
  cin  >> n;
  vector<ll> a(n);
  vector<ll> b(n);

  for(ll i = 0; i< n;i++) {
    cin >> a[i];
    cin >> b[i];
  }

  cout << megalomania(a, b);
}
*/
