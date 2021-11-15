#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  int n, x;
  cin >> n >> x;
  if (x < 1 << (n - 1)) {
    cout << "impossible" << endl;
    return 0;
  }
  cout << x << endl;
  int val = 1 << (n - 1);
  for (int i = 1; i < n; i++) {
    val >>= 1;
    cout << (x - val);
    x -= val;
    for (int j = 0; j < i; j++) {
      cout << " " << val;
    }
    cout << endl;
  }
}
