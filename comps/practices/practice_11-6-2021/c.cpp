#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, h;
  cin >> n >> h;
  vector<int> cards(n);
  map<int, int> pairs;
  priority_queue<pii> pq;
  for (int i = 0; i < n; i++) {
    cin >> cards[i];
    if (pairs.find(cards[i]) != pairs.end())
      pairs[cards[i]] = pairs[cards[i]] + 1;
    else
      pairs[cards[i]] = 1;
  }

  for (auto &key : pairs) {
    pii curr = {key.second, key.first};
    pq.push(curr);
  }

  vector<int> curr;
  vector<pii> currUsed;
  int cnt = 0;
  while (pq.size() > 0) {
    if (curr.size() == h) {
      cnt++;
      for (int i = 0; i < h; i++) cout << curr[i] << " ";
      cout << endl;
      for (int i = 0; i < currUsed.size(); i++) pq.push(currUsed[i]);
      currUsed.clear();
      curr.clear();
    }
    pii top = pq.top();
    // cout << top.first << " " << top.second << endl;
    pq.pop();
    top.first = top.first - 1;
    curr.push_back(top.second);
    if (top.first != 0) currUsed.push_back(top);
  }
  if (curr.size() == h) {
    cnt++;
    for (int i = 0; i < h; i++) cout << curr[i] << " ";
    cout << endl;
    curr.clear();
  }
  if (cnt == 0) cout << "impossible" << endl;
}
