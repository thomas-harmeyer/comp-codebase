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
        int s;
        double long longitude, latitude;
        cin >> s >> longitude >> latitude;
        double long ex, ey, ez;
        double long earth_radius = 6371;
        double long PI = 3.141592653589793;
        latitude *= PI/180.0;
        longitude *= PI/180.0;
        ez = earth_radius * sinl(latitude);
        double long ring_radius = earth_radius * cosl(latitude);
        ex = ring_radius * sinl(longitude);
        ey = ring_radius * cosl(longitude);

        double long alpha, beta, r, x;
        for(int  i = 0; i < s; i++){
            cin >> alpha >> beta >> r >> x; 
            alpha *= PI / 180.0;
            beta *= PI / 180.0;
            x *= 2 * PI;

            //Local Vector
            double long la, lb;
            lb = sinl(x);
            la = cosl(x);

            //Global Vectors
            double long ax, ay, az, bx, by, bz;
            //A is pointed to equator interseciton, b is perpendicular
            az = 0;
            ax = r*sinl(alpha);
            ay = r*cosl(alpha);

            bz = r*sinl(beta);
            by = 0;
            bx = r*cosl(beta);

            //Rotate Around Z
            bx = cosl(alpha)*bx;
            by = -sin(alpha)*bx;

            double long fx = ax * la + bx * lb;
            double long fy = ay * la + by * lb;
            double long fz = az * la + bz * lb;

            double long distance =
                sqrtl((fx - ex) * (fx - ex) + (fy - ey) * (fy - ey) +
                      (fz - ez) * (fz - ez));

            double long time = distance / 299792.458;
            cout << fixed << setprecision(10) << time << endl;
        }

        //cout << ex << " " << ey << " " << ez << " " << endl;
}
