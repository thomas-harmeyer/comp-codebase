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
  string s;
  cin >> s;
  if (s.size() >= 2) {
    if (s[1] >= '5') {
      if (s[0] == '9') {
        s = '1' + s;
      } else {
        s[0]++;
      }
    }
    rep(i, 1, s.size()) { s[i] = '0'; }
  }
  cout << s << endl;
}
