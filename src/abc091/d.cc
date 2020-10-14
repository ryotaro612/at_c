#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int boundary_eq(ll mod_a, vector<ll> mod_b, int n, ll t) {
  int lb = -1, ub = n;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    //cout << lb << "  " << ub << " mid: " << mid << " sum: " << mod_a + mod_b[mid] << endl;
    if (mod_a + mod_b[mid] >= t) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  return ub;
}
int boundary(ll mod_a, vector<ll> mod_b, int n, ll t) {
  int lb = -1, ub = n;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    //cout << lb << "  " << ub << " mid: " << mid << " sum: " << mod_a + mod_b[mid] << endl;
    if (mod_a + mod_b[mid] < t) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  return lb;
}

int boundary_eq2(vector<ll> mod_b, int n, ll t) {
  int lb = -1, ub = n;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    //cout << lb << "  " << ub << " mid: " << mid << " sum: " << mod_a + mod_b[mid] << endl;
    if (mod_b[mid] >= t) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  return ub;
}
int boundary2(vector<ll> mod_b, int n, ll t) {
  int lb = -1, ub = n;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    //cout << lb << "  " << ub << " mid: " << mid << " sum: " << mod_a + mod_b[mid] << endl;
    if (mod_b[mid] < t) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  return lb;
}

ll solve(int n, vector<ll> a, vector<ll> b) {
  ll res = 0;
  for (int k = 29; k >= 0; k--) {
    //cout << "bit: " << k << endl;
    ll bekihigh = 1 << (k + 1), bekilow = (1 << k);
    for (int i = 0; i < n; i++) {
      a[i] %= bekihigh;
      b[i] %= bekihigh;
    }
    sort(b.begin(), b.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
      count += (lower_bound(b.begin(), b.end(), 2*bekilow - a[i]) - lower_bound(b.begin(), b.end(), bekilow - a[i]));
      count += (lower_bound(b.begin(), b.end(), 4*bekilow - a[i]) - lower_bound(b.begin(), b.end(), 3*bekilow - a[i]));
    }
    //cout << "count " << count << endl;
    if (count % 2 == 1) {
      res += bekilow;
    }
  }
  return res;
}
/*
int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  cout << solve(n, a, b);
}
*/

/*
ll solve(int n, vector<ll> a, vector<ll> b) {
  ll res = 0;
    vector<ll> mod_a(n), mod_b(n);
  for (int k = 0; k < 28; k++) {
    //cout << "bit: " << k << endl;
    for (int i = 0; i < n; i++) {
      mod_a[i] = a[i] % (1 << (k + 1));
      mod_b[i] = b[i] % (1 << (k + 1));
    }
    sort(mod_b.begin(), mod_b.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
      //cout << "i " << i << endl;
      int index_start = boundary_eq(mod_a[i], mod_b, n, 1 << k);
      //cout << " index start0: " << index_start << endl;
      if (index_start != n) {
        int index_end = boundary(mod_a[i], mod_b, n, 1 << (k + 1));
        //cout << " index end0: " << index_end << endl;
        count += (index_end - index_start + 1);
      }
      index_start = boundary_eq(mod_a[i], mod_b, n, 3 * (1 << k));
      //cout << " index start1: " << index_start << endl;
      if (index_start != n) {
        int index_end = boundary(mod_a[i], mod_b, n, 4 * (1 << k));
        //cout << " index end1: " << index_end << endl;
        count += (index_end - index_start + 1);
      }
    }
    //cout << "count " << count << endl;
    if (count % 2 == 1) {
      res += (1 << k);
    }
  }
  return res;
}
*/