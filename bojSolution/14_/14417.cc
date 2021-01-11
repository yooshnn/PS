#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tup;

struct Fenwick {
    ll cap;
    vector<ll> tree;

    Fenwick(int size) {
        cap = size + 1;
        tree.resize(cap, 0);
    }

    void update(int i) {
		i += 1; // shift 0-index
        while (i < cap) {
            tree[i] += 1;
            i += i & -i;
        }
    }
    ll ask(int i) const {
        ll ret = 0;
		i += 1; // shift 0-index
        while (i > 0) {
            ret += tree[i];
            i -= i & -i;
        }
        return ret;
    }
};

vector<int> manacher(string src) {
	int srcLen = src.size(); src.resize(srcLen * 2 + 1, '#');
	for (int i = srcLen - 1; i >= 0; --i) src[i * 2 + 1] = src[i], src[i] = '#';

	int c = 0, r = 0, len = src.size();
	vector<int> ret(len, 0);
	for (int i = 0; i < len; ++i) {
		int sym = 2 * c - i;
		if (i < r) ret[i] = min(r - i, ret[sym]);
		while (i - ret[i] > 0 && i + ret[i] - 1 < len && src[i - ret[i] - 1] == src[i + ret[i] + 1]) ret[i]++;
		if (ret[i] + i > r) r = ret[i] + i, c = i;
	}
	return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	string src; cin >> src;
	int srcLen = src.size();

	Fenwick T(srcLen*2 + 2);

	int Q; cin >> Q;
	vector<int> res(Q, 0);
	vector<int> index(Q), center[srcLen*2 + 1];
	vector<int> pal = manacher(src);

	// Query
	for (int i = 0, p, l; i < Q; ++i) {
		cin >> p >> l;
		index[i] = p;
		if (l == 0) res[i] = 1;
		l = 2*p + max(1, l);
		if (l < srcLen*2 + 1) center[l].push_back(i);
	}

	// Process
	for (int i = srcLen*2; i > 0; --i) {
		// cout << "index : " << i << endl;
		int p = i - max(0, pal[i] - 1);
		T.update(p);
		// for (int j = 0; j <= srcLen*2; ++j) cout << T.ask(j) << " "; cout << endl;
		// if (center[i].size() != 0) cout << "QUERY ";
		for (int& q : center[i]) {
			int tar = index[q]*2 + 1;
			// cout << "#" << q << " : " << tar << ", "; 
			res[q] += T.ask(tar);
		}
		// if (center[i].size() != 0) cout << endl;
	}

	for (int& r : res) cout << r << "\n";

    return_0;
}