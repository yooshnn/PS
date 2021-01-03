#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct query1 {
    int i, v;
    query1(int I, int V) {i = I, v = V;}
};
struct query2 {
    int i, j, k, r, a;
    query2(int K, int I, int J, int A) {k = K, i = I, j = J, a = A;}
    void put(int res) {r = res;}
};

bool cmpQ2(query2 const& lhs, query2 const& rhs) {
    return lhs.k < rhs.k;
}
bool cmpQ2_(query2 const& lhs, query2 const& rhs) {
    return lhs.a < rhs.a;
}

struct Fenwick {
    ll cap;
    vector<ll> arr;
    vector<ll> tree;

    Fenwick(int size) {
        cap = size + 1;
        arr.resize(cap, 0);
        tree.resize(cap, 0);
    }

    void update(int i, ll x) {
        ll diff = x - arr[i];
        arr[i] = x;
        while (i < cap) {
            tree[i] += diff;
            i += i & -i;
        }
    }
    ll ask(int i) const {
        ll ret = 0;
        while (i > 0) {
            ret += tree[i];
            i -= i & -i;
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
    vector<query1> que1;
    vector<query2> queries;
    int qCnt = 0;
    for (int i = 1, t, a, b, c; i <= Q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            que1.push_back(query1(a, b));
        }
        else {
            cin >> a >> b >> c;
            queries.push_back(query2(a, b, c, qCnt));
            qCnt += 1;
        }
    }
    sort(queries.begin(), queries.end(), cmpQ2);

    ll res[qCnt];

    // for (query2& x : queries) cout << x.k << ", " << x.a << endl;

    int lastProc = 0;
    for (query2& cur : queries) {
        // cout << "QUERY: " << cur.k << " " << cur.i << " ~ " << cur.j << endl;
        for (int z = lastProc; z < cur.k; ++z) {
            query1& q = que1[z];
            // cerr << "update " << q.i << ", " << q.v <<endl;
            T.update(q.i, q.v);
            lastProc = z;
        }
        res[cur.a] = T.ask(cur.j) - T.ask((cur.i)-1);
    }

    for (ll& x : res) cout << x << "\n";

}