#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getDist(int a, int b, int p, int q) {
    return (a - p) * (a - p) + (b - q) * (b - q);
}
inline ll gcd(ll dx, ll dy) {
    dx = abs(dx), dy = abs(dy);
    return dy == 0 ? dx : gcd(dy, dx % dy);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll maxDist = 1e18;
    ll gx, gy, x, y, dx, dy; cin >> gx >> gy >> x >> y >> dx >> dy;
    ll dgcd = gcd(dx, dy);
    dx /= dgcd, dy /= dgcd;
    ll rx, ry;
    while (1) {
        ll req = getDist(x, y, gx, gy);
        if (req < maxDist) {
            maxDist = req;
            rx = x, ry = y;
        }
        else break;
        x += dx, y += dy;
    }
    cout << rx << " " << ry;
}