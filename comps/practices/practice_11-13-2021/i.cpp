#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main() {
        cin.tie(0)->sync_with_stdio(0);
        cin.exceptions(cin.failbit);
        int n;
        int heroes[1000];
        int temp;

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> heroes[i];
        }
        for(int i = 0; i < n; i++){
            cin >> temp;
            heroes[i]-=temp;
        }
        if(heroes[0] > 0){
            cout << 0 << endl;
            return 0;
        }

        int minHours = -heroes[0];
        for(int i = 0; i < n; i++){
            heroes[i] += minHours;
        }

        int i = 0;
        while(i < n && heroes[i] == 0) i++;
        if(i < n && heroes[i] > 0) {
            cout << minHours << endl;
        }else{
            cout << (minHours + 1) << endl;
        }

}
