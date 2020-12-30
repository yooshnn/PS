#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fenwick {
    ll cap;
    vector<ll> arr, tree;

    Fenwick(int size) {
        cap = size + 1;
        arr.resize(cap, 0);
        tree.resize(cap, 0);
    }

    void update(int i, ll x) {
        arr[i] = x;
    }
    void update(int i, int j, ll x) {
        while (i < cap) {
            tree[i] ^= x;
            i += (i & -i);
        }
        j += 1;
        while (j < cap) {
            tree[j] ^= x;
            j += (j & -j);
        }
    }

    ll ask(int i) const {
        ll ret = arr[i];
        while (i > 0) {
            ret ^= tree[i];
            i -= (i & -i);
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, Q;

    cin >> N;
    Fenwick T(N);

    for (int i = 1; i <= N; ++i) {
        ll t; cin >> t;
        T.update(i, t);
    }

    cin >> Q;

    for (int i = 1; i <= Q; ++i) {
        ll a, b, c, d; cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            T.update(b + 1, c + 1, d);
        }
        else {
            cin >> b;
            cout << T.ask(b + 1) << "\n";
        }
    }
}