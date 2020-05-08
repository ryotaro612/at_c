#include<string>
#include<iostream>
#include<map>

using namespace std;

long long multiple_of_2019(string s) {
  map<long long, long long> m;
  long long t = 0;
  long long n = s.size();
  m[0]=1;
  long long ten = 1;
  for(long long i=n-1;i>=0;i--) {
    long long acc = 0;
    if(i != n-1)
      ten *=10;
    acc = ten;
    acc %= 2019;
    long long a = s[i] - '0';    
    acc *= a;
    acc = acc % 2019;
    t += acc;
    t = t % 2019;
    m[t] = m[t] + 1;
    cout << i << " -> a " << a << " t -> " << t << endl;
  }
  long long ans = 0;
  for(auto i = m.begin();i != m.end();i++) {
    long long v = i->second;
    if(v == 0)
      continue;
    ans += (v * (v-1))/2;
  }
  return ans;
}

/*
int main() {
  string s;
  cin >> s;
  cout << multiple_of_2019(s); 
}

*/
