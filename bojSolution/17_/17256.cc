#include <iostream>
using namespace std;

struct Cake {
    int x, y, z;
};

void solve(Cake a, Cake c) {
    cout << c.x - a.z << " " << c.y / a.y << " " << c.z - a.x;
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    Cake cakeA, cakeC;
    cin >> cakeA.x >> cakeA.y >> cakeA.z;
    cin >> cakeC.x >> cakeC.y >> cakeC.z;
    solve(cakeA, cakeC);

    return 0;
}