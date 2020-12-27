#include <bits/stdc++.h>
using namespace std;

int grundy[3][3]{
    {0, 1, 2},
    {1, 2, 0},
    {2, 0, 1}
};

int calc(int r, int c) {
    int b = 3 * ((r / 3) ^ (c / 3));
    int p, q; p = r % 3, q = c % 3;
    return b + grundy[p][q];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, r = 0, p, q;
    cin >> n;
    while (n--) {
        cin >> p >> q;
        r ^= calc(p, q);
    }
    cout << (r == 0 ? "cubelover" : "koosaga");
}