#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int m, a, b;
    int d;
    while (1) {
        cin >> m >> a >> b;
        if (m == 0) break;
        d = round((m / static_cast<double>(a) - m / static_cast<double>(b)) * 3600);
        cout << (d/3600) << ":" << setfill('0') << setw(2) << (d/60)%60 << ":" << setw(2) << d % 60 << "\n";
    }

    return 0;
}