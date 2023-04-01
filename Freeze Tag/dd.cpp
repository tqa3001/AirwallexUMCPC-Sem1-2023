#include <iostream>
#include <cmath>
 
using namespace std;
 
double dist(double x1, double y1, double x2, double y2) {
    // Calculate the Euclidean distance between two points
    return sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2));
}
 
double time_taken(int x, int y, int x1, int y1, int x2, double v, double v1, double m) {
    // Calculate the time taken for Dd to reach the trash bin from their initial position
    double d1 = dist(x, y, x2, m) / v + dist(x2, m, x1, y1) / v1;
    return d1;
}
 
int main() {
    int x, y, x1, y1, x2, k, v, v1;
    cin >> x >> y >> x1 >> y1 >> x2 >> k >> v >> v1;
    double lo = -1e9, hi = 1e9;
    while (hi - lo > 1e-5) {
        double m1 = lo + (hi - lo) / 3;
        double m2 = hi - (hi - lo) / 3;
        double t1 = time_taken(x, y, x1, y1, x2, v, v1, m1);
        double t2 = time_taken(x, y, x1, y1, x2, v, v1, m2);
        if (t1 < t2) hi = m2;
        else lo = m1;
    }
    double ans = time_taken(x, y, x1, y1, x2, v, v1, lo);
    // cout<<lo<<endl;
    if (ans <= 1.0*k) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
