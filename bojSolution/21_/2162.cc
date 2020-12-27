#include <bits/stdc++.h>
#define y1 Y1
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll, ll> tup;

int root[3010];
int sz[3010];

int search(int target) {
    if (target == root[target]) return target;
    return root[target] = search(root[target]);
}
void merge(int a, int b) {
    a = search(a); b = search(b);
    if (a == b) return;
    root[b] = a;
}

int ccw(pll a, pll b, pll c) {
    ll res = (a.first * b.second + b.first * c.second + c.first * a.second)
        - (a.second * b.first + b.second * c.first + c.second * a.first);
    return (res == 0 ? 0 : res / (res > 0 ? res : -res));
}
int lineIntersect(pair<pll, pll> x, pair<pll, pll> y) {
    pll a = x.first, b = x.second, c = y.first, d = y.second;
    ll ab = ccw(a, b, c) * ccw(a, b, d), cd = ccw(c, d, a) * ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for (int i = 1; i <= N; ++i) root[i] = i;
    
    vector<pair<pll, pll>> lines;
    for (int i = 1, a, b, c, d; i <= N; ++i) {
        cin >> a >> b >> c >> d;
        lines.push_back({ {a, b}, {c, d} });
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) continue;

            if (lineIntersect(lines[i - 1], lines[j - 1])) {
                merge(i, j);
            }

        }
    }

    map<int, int> res;
    int r0 = 0, r1 = 0;
    for (int i = 1; i <= N; ++i) {
        if (res.find(search(i)) == res.end()) {
            r0 += 1;
        }
        res[root[i]] += 1;
        r1 = max(r1, res[root[i]]);
    }

    cout << r0 << "\n" << r1;

}