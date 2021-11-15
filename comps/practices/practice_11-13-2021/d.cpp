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
        cin >> n;
        vector<int> arr(1000000);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        //Get Lower Bound
        int low = 0;
        int high = arr[0];
        int save = high;
        while(low <= high){
            int guess = (low+high)/2;
            int val = arr[0] - guess;
            int works = -1;
            for(int i = 1; i < n; i++){
                if(val > arr[i]){
                    works = i%2;
                    break;
                }
                val = arr[i] - val;
            }
            if(works != -1){
                if(works == 0){
                    high = guess - 1;
                }else{
                    low = guess + 1;
                }
            }else{
                save = guess;
                high = guess - 1;
            }
        }
        int lower_bound = save;

        low = 0;
        high = arr[0];
        save = low;
        while (low <= high) {
            int guess = (low + high) / 2;
            int val = arr[0] - guess;
            int works = -1;
            for (int i = 1; i < n; i++) {
                if (val > arr[i]) {
                    works = i % 2;
                    break;
                }
                val = arr[i] - val;
            }
            if (works != -1) {
                if (works == 0) {
                    high = guess - 1;
                } else {
                    low = guess + 1;
                }
            } else {
                save = guess;
                low = guess + 1;
            }
        }
        int higher_bound = save;
        if(higher_bound < lower_bound){
            cout << 0 << endl;
        }else{
            cout << (higher_bound - lower_bound + 1) << endl;
        }
}
