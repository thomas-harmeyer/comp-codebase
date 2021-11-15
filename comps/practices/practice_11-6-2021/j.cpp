#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m;
vi prog;
map<int, int> buildBack;
map<int, vi> machMap;  // machine number -> list of machines indecies
long double angleX;
long double memo[102][102];

pair<long double, long double> getCord(int i) {
  if (i == -1) {
    return {0, 0};
  }
  long double x = cos(i * angleX);
  long double y = sin(i * angleX);
  return {x, y};
}

long double dist(pair<long double, long double> a,
                 pair<long double, long double> b) {
  long double aa = (a.first - b.first);
  aa *= aa;
  long double bb = (a.second - b.second);
  bb *= bb;
  return sqrtl(aa + bb);
}

long double getDist(int u, int v) { return dist(getCord(u), getCord(v)); }

long double rec(int curPos, int curIndex) {
  if (curIndex == n - 1) {
    return 0;
  }
  if (memo[curPos + 1][curIndex + 1] != -1) {
    return memo[curPos + 1][curIndex + 1];
  }
  long double mn = INT_MAX;
  int nextI = curIndex + 1;
  int temp;
  int to;
  for (auto v : machMap[prog[nextI]]) {
    temp = mn;
    mn = min(mn, rec(v, nextI) + getDist(curPos, v));
    if (temp != mn) {
      to = v;
    }
  }
  return memo[curPos + 1][curIndex + 1] = mn;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n;
  rep(i, 0, n) {
    int x;
    cin >> x;
    x--;
    prog.push_back(x);
  }
  rep(i, 0, 102) rep(j, 0, 102) memo[i][j] = -1;
  cin >> m;
  angleX = (2L * 3.14159265359L) / (long double)m;
  rep(i, 0, m) {
    int x;
    cin >> x;
    x--;
    machMap[x].push_back(i);
  }
  cout << fixed << setprecision(8) << rec(-1, -1) << endl;

  return 0;
}
