#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    ll lp = 0, rp = n, mid;
    while (lp <= rp) {
        mid = (lp + rp) / 2;
        if (mid * (n - mid) == k - n - 1) {
            cout << "YES";
            return 0;
        }
        if (mid * (n - mid) > k - n - 1) {
            lp = mid + 1;
        }
        else {
            rp = mid - 1;
        }
    }

    cout << "NO";
    return 0;

}