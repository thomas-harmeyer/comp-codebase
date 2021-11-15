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
    int value[102][102];
    int count[102][102];
    bool grid[102][102];
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            value[i][j] = 0;
            count[i][j] = 0;
            grid[i][j] = false;
        } 
    }

    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h + 2; i++){
        for(int j = 0; j < w + 2; j++){
            cin >> value[i][j];
        }
    }

    //Go from bottom left across, then down
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int expected = value[i][j] - count[i][j];
            if(expected >= 2 || expected < 0){
                cout << "impossible" << endl;
                return 0;
            }else{
                grid[i+1][j+1] = expected;
                count[i][j]+=expected;
                count[i][j+1]+=expected;
                count[i][j+2]+=expected;
                count[i+1][j]+=expected;
                count[i+1][j+1]+=expected;
                count[i+1][j+2]+=expected;
                count[i+2][j]+=expected;
                count[i+2][j+1]+=expected;
                count[i+2][j+2]+=expected;
            }
        }
        //Check the last couple
        if(value[i][w] != count[i][w] || value[i][w+1] != count[i][w+1]){
            cout << "impossible" << endl;
            return 0;
        }
    }

    //Check last two rows
    for(int i = h; i < h+2; i++){
        for(int j = 0; j < w+2; j++){
            if(value[i][j] != count[i][j]){
                cout << "impossible" << endl;
                return 0;
            }
        }
    }

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            char output = (grid[i][j]) ? 'X' : '.';
            cout << output;
        }
        cout << endl;
    }

}
