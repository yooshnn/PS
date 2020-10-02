#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N; cin >> N;
    int lp = 1, rp = N, mid, req;

    for (int i = 1; i <= 50; ++i) {
        int mid = (lp + rp) / 2;
        cout << "? " << mid << "\n" << endl;
        cin >> req;

        if (req == 1) rp = mid - 1;
        else if (req == -1) lp = mid + 1;
        else {
            cout << "= " << mid << "\n" << endl;
            return 0;
        }
    }

    return 0;
}