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

    void update(int i, int j, ll x) {
        while (i < cap) {
            tree[i] += x;
            i += (i & -i);
        }
        j += 1;
        while (j < cap) {
            tree[j] -= x;
            j += (j & -j);
        }
    }

    ll ask(int i) const {
        ll ret = arr[i];
        while (i > 0) {
            ret += tree[i];
            i -= (i & -i);
        }
        return ret;
    }
};

struct Tree {
	int cap, cnt;
	vector<vector<int>> adj;
	vector<int> uid, lim;

	Tree(int size) {
		cap = size + 1;
		cnt = 1;
		adj.resize(cap);
		lim.resize(cap, 0);
		uid.resize(cap, 0);
	}

	void insert(int i, int t) {
		adj[t].push_back(i); // add q as p's child
	}
	int calc(int id) {
		uid[id] = cnt;
		cnt += 1;

		int req = uid[id];
		for(int& i: adj[id]) req = calc(i);
		return lim[uid[id]] = req;
	}
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, Q;

    cin >> N >> Q;
    Fenwick T(N);
	Tree U(N);

	ll t; cin >> t;
    for (int i = 2; i <= N; ++i) {
        cin >> t;
        U.insert(i, t);
    }

	U.calc(1);

    for (int i = 1; i <= Q; ++i) {
        ll oper, a, b; cin >> oper;
		if (oper == 1) {
			cin >> a >> b;
			T.update(U.uid[a], U.lim[U.uid[a]], b);
		}
		else {
			cin >> a;
			cout << T.ask(U.uid[a]) << "\n";
		}
    }

	// cout << endl; system("pause");
}