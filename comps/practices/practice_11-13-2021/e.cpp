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
    int t;
    cin >> t;
    vi a;

    int max = 10000001;
    vector<bool> isPrime(max, true);
    for (int i = 2; i < max; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * 2; j < max; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 0; i < t; i++) {
        long double a, b;
        cin >> a >> b;
        ll a1 = (ll)round(a * 1000000ll);
        ll b1 = (ll)round(b * 1000000ll);
        if (a1 == 0 || b1 == 0) {
            cout << "impossible" << endl;
            continue;
        }
        ll gcd = __gcd(a1, b1);
        if (a1 == 0 || b1 == 0) {
            cout << "impossible" << endl;
            continue;
        }
        a1 /= gcd;
        b1 /= gcd;
        if (a1 >= max || b1 >= max) {
            cout << "impossible" << endl;
            continue;
        }
        if (a1 == b1) {
            cout << 2 << " " << 2 << endl;
        } else if (isPrime[a1] && isPrime[b1]) {
            cout << a1 << " " << b1 << endl;
        } else
            cout << "impossible" << endl;
    }
}
