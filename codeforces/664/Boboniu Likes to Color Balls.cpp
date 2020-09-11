#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int T;
int r, g, b, w;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    cin >> T;
    while (T--) {
        cin >> r >> g >> b >> w;

        int r_, g_, b_, w_;
        r_ = r % 2;
        g_ = g % 2;
        b_ = b % 2;
        w_ = w % 2;

        if (r == 0 || g == 0 || b == 0) {
            if (r_ + g_ + b_ + w_ == 3 || r_ + g_ + b_ + w_ == 2) cout << "No\n";
            else cout << "Yes\n";
            continue;
        }
        if (r_ + g_ + b_ + w_ != 2) {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }

    return 0;
}