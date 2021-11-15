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
  int n, c;
  cin >> n >> c;
  vector<ll> vals(n);
  for (int i = 0; i < n; i++) {
    cin >> vals[i];
  }
  sort(vals.begin(), vals.end());
  int left = 0;
  int right = vals.size() - 1;
  int cnt = 0;
  while (left <= right) {
    //cout << left << " " << right << endl;
    if (vals[left] + vals[right] <= c) {
      cnt++;
      left++;
      right--;
    } else {
      cnt++;
      right--;
    }
  }
  cout << cnt << endl;
}
