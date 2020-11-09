#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline ll input() { ll num = 0, ch; while ((ch = getchar()) > 47) { num = num * 10 + ch - '0'; } return num; }

pii magic(int a, int b, int c, int d) {
    int temp[4]{ a, b, c, d };
    sort(temp, temp + 4);
    return { temp[2], temp[3] };
}

struct segt {
    int depth, f;
    pii* tree;

    segt(int n) {
        tree = new pii[n * 4];
        for (depth = 1; n > (int)pow(2, depth - 1); ++depth);
        f = (int)pow(2, depth - 1) - 1;
    }

    void build() {
        for (int i = depth - 1; i >= 1; --i) {
            for (int j = 0; j < (int)pow(2, i - 1); ++j) {
                int cur = (int)pow(2, i - 1) + j;
                tree[cur] = magic(tree[cur * 2].first, tree[cur * 2].second, tree[cur * 2 + 1].first, tree[cur * 2 + 1].second);
            }
        }
    }
    void update(int id, ll val) {
        tree[f + id] = { val, 0 };
        id = (id + 1) / 2;
        for (int i = depth - 1; i >= 1; --i) {
            int cur = (int)pow(2, i - 1) - 1 + id;
            tree[cur] = magic(tree[cur * 2].first, tree[cur * 2].second, tree[cur * 2 + 1].first, tree[cur * 2 + 1].second);
            id = (id + 1) / 2;
        }
    }
    pii ask(int p, int q) {
        pii ret = { 0, 0 }; p += f, q += f;
        while (p <= q) {
            if (p % 2 == 1) ret = magic(ret.first, ret.second, tree[p].first, tree[p].second);
            if (q % 2 == 0) ret = magic(ret.first, ret.second, tree[q].first, tree[q].second);
            p = (p + 1) / 2, q = (q - 1) / 2;
        }
        return ret;
    }

};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, Q;
    N = input();

    segt T(N);

    int cc;
    for (int i = 1; i <= N; ++i) {
        cc = input();
        T.tree[i + T.f] = { cc, 0 };
    }
    T.build();

    Q = input();
    ll a, b, c;
    while (Q--) {
        a = input(), b = input(), c = input();
        if (a == 1) T.update(b, c);
        else {
            pii req = T.ask(b, c);
            cout << req.first + req.second << "\n";
        }
    }
}