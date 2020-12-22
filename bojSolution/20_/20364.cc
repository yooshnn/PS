#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, Q;
vector<bool> quack;

int solve(int tar) {
    int ret = 0, cur = tar;
    while (cur != 1) {
        if (quack[cur]) ret = cur;
        cur /= 2;
    }
    if (ret == 0) quack[tar] = true;
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    quack.resize(N + 1, false);

    int x;
    while (Q--) {
        cin >> x;
        cout << solve(x) << "\n";
    }
}