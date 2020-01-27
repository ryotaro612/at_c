#include<iostream>
#include<utility>

using namespace std;

long long len_burger[51];
long long len_patty[51];

long long count_len_burger(int n) {
  if(len_burger[n] != -1) {
    return len_burger[n];
  }
  if(n == 0) {
    return len_burger[n] = 1;
  }
  long long len = count_len_burger(n-1);
  return len_burger[n] = 1 + len + 1 + len + 1;
}
long long count_patty(int n) {
  if(len_patty[n] != -1) {
    return len_patty[n];
  }
  if(n == 0) {
    return len_patty[n] = 1;
  }
  return len_patty[n] = 2 * count_patty(n-1) + 1;
}

pair<long long, long long> p_burg(int n, long long x) {
  if(n==0) {
    if(x >= 1) {
      return make_pair(1, 1);
    }
    return make_pair(0, 0);
  }
  if(x <= 1) {
    return make_pair(0, 1);
  }
  long long remain = x-1;
  long long smaller_burger = count_len_burger(n-1);
  if(remain <= smaller_burger) {
    pair<long long, long long> p = p_burg(n-1, remain);
    return make_pair(p.first, 1 + p.second);
  }
  remain -= smaller_burger + 1;
  long long num_patty = count_patty(n-1) + 1;
  if(remain == 0) {
    return make_pair(num_patty, x);
  }
  if(remain <= smaller_burger) {
    pair<long long, long long> p = p_burg(n-1, remain);
    return make_pair(num_patty + p.first, 1 + smaller_burger + 1 + p.second);
  }
  return make_pair(num_patty + count_patty(n-1), 3 + count_len_burger(n-1)*2);
}

long long christmas(int n, long long x) {
  for(int i=0;i<51;i++) {
    len_burger[i] = len_patty[i] = -1;
  }
  return p_burg(n, x).first;
}

/*
int main() {
  int n;
  long long x;
  cin >> n;
  cin >> x;
  cout << christmas(n, x);
}
*/
