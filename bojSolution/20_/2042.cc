#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll MAX = 1000001;
ll N, Q;

struct segTree {
    ll tree[MAX * 4];
    ll N, depth, x;
    segTree(int n) {
        fill(tree, tree + MAX * 4, 0);
        N = n, depth = 1;
        while (N > (ll)pow(2, depth - 1)) depth++;
        x = (ll)pow(2, depth - 1) - 1;
    }
    void build() {
        for (int i = depth - 1; i >= 1; --i) {
            for (int j = 0; j < (int)pow(2, i - 1); ++j) {
                ll id = (ll)pow(2, i - 1) + j;
                tree[id] = tree[id * 2] + tree[id * 2 + 1];
            }
        }
    }
    void update(ll id, ll val) {
        tree[x + id] = val;
        id = (id + 1) / 2;
        for (int i = depth - 1; i >= 1; --i) {
            int cur = (int)pow(2, i - 1) - 1 + id;
            tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
            id = (id + 1) / 2;
        }
    }
    ll ask(ll p, ll q) {
        ll ret = 0; p += x, q += x;
        while (p <= q) {
            if (p % 2 == 1) ret += tree[p];
            if (q % 2 == 0) ret += tree[q];
            p = (p + 1) / 2;
            q = (q - 1) / 2;
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int M, K;

    cin >> N >> M >> K;
    segTree* sT = new segTree(N);

    ll* s = sT->tree, x = sT->x;
    for (int i = 1; i <= N; ++i) cin >> s[i + x];
    sT->build();

    // cin >> Q;
    Q = M + K;
    for (int i = 0; i < Q; ++i) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) sT->update(a, b);
        else cout << sT->ask(a, b) << "\n";
    }

    return 0;
}