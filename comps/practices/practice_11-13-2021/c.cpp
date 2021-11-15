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
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[m];
    rep(i,0,n){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].emplace_back(y,z);
    }
    
    rep(i,0,m){     
        queue<pair<pair<int,int>,int>> q;    
        if(adj[q.front].size)

    }
    


}
