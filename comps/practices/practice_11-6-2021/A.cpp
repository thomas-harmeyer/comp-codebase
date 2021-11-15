#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, map<int, int>> slots;
map<int, vector<int>> coins;

struct Tree {
  typedef int T;
  static constexpr T unit = INT_MAX;
  T f(T a, T b) { return min(a, b); }
  vector<T> s;
  int n;
  Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;) s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) {
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main() {
  int s, c;
  int a, b;
  cin >> s;
  for (int i = 1; i <= s; i++) {
    cin >> a >> b;
    if (slots.count(a) == 1) {
      if (slots[a].count(b) != 1) {
        slots[a][b] = i;
      }
    } else {
      slots[a] = {{b, i}};
    }
  }

  cin >> c;
  for (int i = 0; i < c; i++) {
    cin >> a >> b;
    if (coins.count(a) == 1) {
      coins[a].push_back(b);
    } else {
      coins[a] = vector<int>();
      coins[a].push_back(b);
    }
  }

  // Run
  map<int, int> coins_F;
  Tree weight_segment_tree(100001);
  int totalDistance = 0;
  for (int i = 100000; i >= 0; i--) {
    for (auto s : slots[i]) {
      weight_segment_tree.update(s.first, s.second);
    }

    for (auto c : coins[i]) {
      totalDistance += (weight_segment_tree.query(0, c + 1));
    }
  }

  cout << totalDistance << endl;
  return 0;
}
