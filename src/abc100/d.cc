#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct triplet {
  ll x, y, z;
};

ll d(int n, int m, vector<ll> x, vector<ll> y, vector<ll> z) {
  vector<triplet> xyz(n);
  for(int i=0;i<n;i++) {
    xyz[i] = {x[i], y[i], z[i]};
  }
  ll res = 0;
  for(int i=0;i<8;i++) {
    bool x_p = i & 1;
    bool y_p = i & 2;
    bool z_p = i & 4;

    sort(xyz.begin(), xyz.end(), [&](auto const& lhs, auto const& rhs) {
	ll xx_1 = x_p ? lhs.x : -lhs.x;
	ll yy_1 = y_p ? lhs.y : -lhs.y;
	ll zz_1 = z_p ? lhs.z : -lhs.z;

	ll xx_2 = x_p ? rhs.x : -rhs.x;
	ll yy_2 = y_p ? rhs.y : -rhs.y;
	ll zz_2 = z_p ? rhs.z : -rhs.z;
	return xx_1 + yy_1 + zz_1 > xx_2 + yy_2 + zz_2;
	});
    ll temp = 0;
    for(int j=0;j<m;j++) {
      temp += ((x_p ? xyz[j].x : -xyz[j].x) + (y_p ? xyz[j].y : -xyz[j].y)+ (z_p ? xyz[j].z : -xyz[j].z));
    }
    res = max(res, temp);
  }

  return res;
}
/*
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> x(n);
  vector<ll> y(n);
  vector<ll> z(n);
  for(int i=0;i<n;i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  cout << d(n, m, x, y, z);
}
*/
