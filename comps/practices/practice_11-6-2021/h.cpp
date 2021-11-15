#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  int hat_map[100001];
  vector<pair<int, int>> occurences;
  int c, n;
  cin >> c >> n;
  int current;
  cin >> current;
  current--;
  for (int i = 0; i < c; i++) {
    occurences.emplace_back(0, i);
    hat_map[i] = i;
  }
  occurences[current].first = -1;
  int hat;
  for (int i = 1; i < n; i++) {
    cin >> hat;
    hat--;
    occurences[hat_map[hat]].first++;

    int temp = hat_map[current];
    hat_map[current] = hat_map[hat];
    hat_map[hat] = temp;
    current = hat;
  }

  sort(all(occurences));

  ll sum = 0;
  string second_line = "";
  for (int i = c - 1; i > 0; i--) {
    second_line += to_string(occurences[i].second + 1) + " ";
    sum += occurences[i].first * (c - i);
  }

  cout << sum << endl << second_line << endl;
}
