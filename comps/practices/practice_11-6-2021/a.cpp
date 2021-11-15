#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, map<int, int>> slots;
map<int, map<int, int>> coins;

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
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int s, c;
  vector<pii> slots, slotsR, coins, coinsR;
  cin >> s;
  Tree seg(100000);
  rep(i, 0, s) {
    pii x;
    cin >> x.first >> x.second;
    slots.push_back(x);           // width,mass
    seg.update(x.second, i + 1);  // stores weight
  }
  cin >> c;
  rep(i, 0, c) {
    pii x;
    cin >> x.first >> x.second;
    coins.push_back(x);
  }
  sort(all(coins));

  sort(all(slots));
  int coinP = 0;
  int slotP = 0;
  ll ans = 0;
  while (coinP < c && slotP < s) {
    while (coins[coinP].first > slots[slotP].first) {
      seg.update(slots[slotP].second, INT_MAX);
      slotP++;
    }
    ans += seg.query(0, coins[coinP].second + 1);
    coinP++;
  }
  cout << ans;
  return 0;
}
