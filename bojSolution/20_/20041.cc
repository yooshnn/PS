#include <bits/stdc++.h>
#define r first
#define c second
using namespace std;
typedef pair<int, int> pii;

int N, r0, c0;
vector<pii> police;

int solve(pii& p) {
    int y = p.r - r0, x = p.c - c0;
    if (y < 0) {
        if (y < -abs(x)) return 1;
        else {
            if (y == x) return -2;
            if (y == -x) return -1;
            if (x < 0) return 2;
            return 0;
        }
    }
    else {
        if (y > abs(x)) return 3;
        else {
            if (y == x) return -4;
            if (y == -x) return -3;
            if (x < 0) return 2;
            return 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    police.resize(N);
    for (pii& p : police) cin >> p.r >> p.c;
    cin >> r0 >> c0;

    set<int> res;
    for (pii& p : police) {
        int req = solve(p);
        if (req >= 0) res.insert(req);
        else {
            if (req == -1) res.insert(0), res.insert(1);
            if (req == -2) res.insert(1), res.insert(2);
            if (req == -3) res.insert(2), res.insert(3);
            if (req == -4) res.insert(3), res.insert(0);
        }
    }

    cout << (res.size() == 4 ? "NO" : "YES");
}