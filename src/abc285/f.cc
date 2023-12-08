#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " " << #__VA_ARGS__       \
       << " = ";                                                               \
  debug_(__VA_ARGS__);
#else
#define dbg(...)
#endif
template <typename Os, typename... Ts>
Os &operator<<(Os &os, const pair<Ts...> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <typename Os, typename T>
typename enable_if<is_same<Os, ostream>::value, Os &>::type
operator<<(Os &os, const T &v) {
  os << "[";
  string sep = "";
  for (auto &x : v) {
    os << sep << x;
    sep = ", ";
  };
  return os << "]";
}

void debug_() { cerr << "\e[39m" << endl; }

template <typename Head, typename... Tail> void debug_(Head H, Tail... T) {
  cerr << H << " ";
  debug_(T...);
}

struct Segment {
  string s;
  vector<int> freq;
  bool is_sorted;
  Segment() : s(""), freq(26, 0), is_sorted(true) {}
  int size() { return s.size(); }
  void append(char c) {
    s.push_back(c);
    freq[c - 'a']++;
  }
  void check_order() {
    bool ok = true;
    rep(i, s.size() - 1) { ok = ok && s[i] <= s[i + 1]; }
    is_sorted = ok;
  }
  void replace(int i, char c) {
    freq[s[i] - 'a']--;
    s[i] = c;
    freq[s[i] - 'a']++;
    check_order();
  }
  bool is_sorted_range(int from, int to) {
    bool ok = true;
    for (int j = from; j < to-1; j++) {
      ok = ok && (s[j] <= s[j + 1]);
    }
    return ok;
  }
  vector<int> freq_range(int from, int to) {
    vector<int> res(26, 0);
    for (int i = from; i < to; i++) {
      res[s[i] - 'a']++;
    }
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> freq(26, 0);
  for (auto c : s) {
    freq[c - 'a']++;
  }
  int seg_size = n / (int)sqrt(n);
  // 12 3
  vector<Segment> segments(1);
  for (auto c : s) {
    if ((int)segments.back().size() == seg_size) {
      segments.push_back(Segment());
    }
    segments.back().append(c);
  }
  rep(i, segments.size()) { segments[i].check_order(); }

  int q;
  cin >> q;
  // for(auto &seg: segments) {
  //   dbg(seg.is_sorted);
  // }
  rep(q_i, q) {
    dbg(q_i);
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      char c;
      cin >> x >> c;
      x--;
      int seg_i = x / seg_size, j = x % seg_size;
      segments[seg_i].replace(j, c);
      freq[s[x] - 'a']--;
      freq[c - 'a']++;
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      int seg_l = l / seg_size;
      bool ok =
          segments[seg_l].is_sorted_range(l % seg_size, segments[seg_l].size());
      //dbg(ok, segments[seg_l].s, l%seg_size);
      int seg_r = r / seg_size;
      ok = ok && segments[seg_r].is_sorted_range(0, r % seg_size + 1);
      for (int seg_i = seg_l + 1; seg_i < seg_r; seg_i++) {
        ok = ok && segments[seg_i].is_sorted;
        ok = ok && segments[seg_i].s.back() <= segments[seg_i].s[0];
      }
      dbg(ok, seg_l, l % seg_size, seg_r, r%seg_size + 1, seg_size);
      if (!ok) {
        cout << "No\n";
        continue;
      }
      vector<int> range_freq =
          segments[seg_l].freq_range(l % seg_size, segments[seg_l].size());
      for (int i = seg_l + 1; i < seg_r; i++) {
        rep(j, 26) { range_freq[j] += segments[i].freq[j]; }
      }
      vector<int> last = segments[seg_r].freq_range(0, r % seg_size + 1);
      rep(j, 26) { range_freq[j] += last[j]; }
      dbg(range_freq);
      int left = 0, right = 25;
      while (range_freq[left] == 0)
        left++;
      while (range_freq[right] == 0)
        right--;
      for (int i = left + 1; i < right; i++) {
        ok = ok && freq[i] == range_freq[i];
      }
      if(ok) {
	cout << "Yes\n";
      } else
	cout << "No\n";
    }
  }
  return 0;
}
