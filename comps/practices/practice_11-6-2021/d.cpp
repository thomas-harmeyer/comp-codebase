#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  vector<long double> distances;
  int k, n;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    long double x, y, z;
    cin >> x >> y >> z;
    long double distance = sqrtl(x * x + y * y + z * z);
    distances.push_back(distance);
  }
  sort(all(distances));
  cout << fixed << setprecision(8) << distances[k - 1] << endl;
}
