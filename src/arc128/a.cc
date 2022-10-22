#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template <class T> void debug(T itr1, T itr2) {
  auto now = itr1;
  while (now < itr2) {
    cout << *now << " ";
    now++;
  }
  cout << endl;
}
#define repr(i, from, to) for (ll i = (ll)from; i < (ll)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i, N) repr(i, 0, N)
#define per(i, N) for (ll i = (ll)N - 1; i >= 0; i--)
#define popcount __builtin_popcount

const ll LLINF = pow(2, 61) - 1;
const ll INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) {
  if (a < b)
    swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
/*
int main() {
  ll N; cin >> N;
  vector<ll> A(N); rep(i,N) cin >> A[i];
  vector<ll> result(N);
  rep(i,N-1) {
    if (A[i]>=A[i+1]) {
      result[i] ^= 1;
      result[i+1] ^= 1;
    }
  }
  debug(all(result));
  return 0;
  }*/
