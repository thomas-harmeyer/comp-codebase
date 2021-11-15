#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll powCool(ll b, ll e) {
    ll ans = 1;
    while(e){
        ans*=b;
        if(ans > 1e16){
            return -1;
        }
        e--;
    }
    return ans;
}


int main() {
        cin.tie(0)->sync_with_stdio(0);
        cin.exceptions(cin.failbit);
        ll m;
        cin >> m;
        //Binary Search for 3D and 4D
        ll low = 1;
        ll high = 1e6;
        ll n;
        while(low <= high){
            n = (low + high)/2;
            ll sum = (n*(n+1)*(2*n+1))/6;
            if(sum > m){
                high = n - 1;
            }else if(sum < m){
                low = n + 1;
            }else{
                cout << "3 " << n << endl;
                return 0;
            }
        }
        //4D
        low = 1;
        high = 3*(1e4);
        while(low <= high){
            n = (low + high)/2;
            ll sum = ((n*n)*(n+1)*(n+1))/4;
            if (sum > m) {
              high = n - 1;
            } else if (sum < m) {
              low = n + 1;
            } else {
              cout << "4 " << n << endl;
              return 0;
            }
        }
        
        for(int i = 4; i < 55; i++){
            ll sum = 1;
            ll j = 2;
            while(sum < m){
                ll addition = powCool(j,i);
                if(addition == -1) break;
                sum+=addition;
                j++;
            }
            if(sum == m){
                cout << (i+1) << " " << (j-1) << endl;
                return 0;
            }
        }

        cout << "impossible" << endl;
}
