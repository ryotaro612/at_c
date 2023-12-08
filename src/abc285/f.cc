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
struct Tree {
  vector<vector<int>> freqs;
  vector<bool> is_sorted;
  string s;
  Tree(string _s) {
    s = _s;
    int size = s.size();
    int i = 1;
    while (i < size)
      i *= 2;
    int n_nodes = size * 2 - 1;
    freqs.resize(n_nodes, vector<int>(26, 0));
    rep(s_i, size) {
      int node_i = freqs.size() / 2 + s_i;
      while (true) {
        freqs[node_i][s[s_i] - 'a']++;
        node_i = (node_i - 1) / 2;
        if (node_i == 0)
          break;
      }
    }
    update_sort_state(0, 0, (tree_size() + 1) / 2);
  }

  void update_sort_state(int node_i, int left, int right) {
    if (tree_size() >= node_i)
      return;
    if (tree_size() / 2 <= node_i) {
      is_sorted[node_i] = true;
      return;
    }
    int mid = (left + right) / 2;
    update_sort_state(node_i * 2 + 1, left, mid);
    update_sort_state(node_i * 2 + 2, mid, right);
    is_sorted[node_i] = is_sorted[node_i * 2 + 1] && is_sorted[node_i * 2 + 2];
    is_sorted[node_i] = is_sorted[node_i] && s[mid - 1] <= s[mid];
  }
  int tree_size() { return freqs.size(); }
  void replace(int i, char c, int node_i, int left, int right) {
    if (i < left || right <= i)
      return;
    if (left + 1 == right) {
      freqs[node_i][s[i] - 'a']--;
      s[i] = c;
      freqs[node_i][c - 'a']++;
      return;
    }
    int mid = (left + right) / 2;
    replace(i, c, node_i * 2 + 1, left, mid);
    replace(i, c, node_i * 2 + 2, mid, right);
    is_sorted[node_i] = is_sorted[node_i * 2 + 1] && is_sorted[node_i * 2 + 2];
    is_sorted[node_i] = is_sorted[node_i] && s[mid - 1] <= s[mid];
  }
  vector<int> get_freq(int l, int r, int node, int left, int right) {
    if (r <= left || right <= l) {
      return vector<int>(26, 0);
    } else if (left <= l && r <= right) {
      return freqs[node];
    }
    vector<int> a = get_freq(l, r, node * 2 + 1, left, (left + right) / 2);
    vector<int> b = get_freq(l, r, node * 2 + 2, (left + right) / 2, right);
    rep(i, 26) { a[i] += b[i]; }
    return a;
  }
};

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
    is_sorted = true;
    rep(i, s.size() - 1) { is_sorted = is_sorted && s[i] <= s[i + 1]; }
  }
  void replace(int i, char c) {
    freq[s[i] - 'a']--;
    s[i] = c;
    freq[s[i] - 'a']++;
    check_order();
  }
  bool is_sorted_range(int from, int to) {
    bool ok = true;
    for (int j = from; j < to - 1; j++) {
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
      s[x] = c;
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      --r;
      int seg_l = l / seg_size, seg_r = r / seg_size;
      vector<int> sub_freq;
      bool ok = true;
      if (seg_l == seg_r) {
        ok = segments[seg_l].is_sorted_range(l % seg_size, r % seg_size + 1);
        sub_freq = segments[seg_l].freq_range(l % seg_size, r % seg_size + 1);
      } else {
        ok = segments[seg_l].is_sorted_range(l % seg_size,
                                             segments[seg_l].size());
        for (int seg_i = seg_l + 1; seg_i < seg_r; seg_i++) {
          ok = ok && segments[seg_i].is_sorted;
        }
        ok = ok && segments[seg_r].is_sorted_range(0, r % seg_size + 1);
        for (int seg_i = seg_l; seg_i < seg_r; seg_i++) {
          ok = ok && segments[seg_i].s.back() <= segments[seg_i + 1].s[0];
        }

        sub_freq =
            segments[seg_l].freq_range(l % seg_size, segments[seg_l].size());
        for (int seg_i = seg_l + 1; seg_i < seg_r; seg_i++) {
          rep(j, 26) { sub_freq[j] += segments[seg_i].freq[j]; }
        }
        vector<int> last = segments[seg_r].freq_range(0, r % seg_size + 1);
        rep(j, 26) { sub_freq[j] += last[j]; }
      }
      dbg(ok, seg_l, l % seg_size, seg_r, r % seg_size + 1, seg_size);
      if (!ok) {
        cout << "No\n";
        continue;
      }

      int left = 0, right = 25;
      while (sub_freq[left] == 0)
        left++;
      while (sub_freq[right] == 0)
        right--;
      for (int i = left + 1; i < right; i++) {
        ok = ok && freq[i] == sub_freq[i];
      }
      if (ok) {
        cout << "Yes\n";
      } else
        cout << "No\n";
    }
  }
  return 0;
}
