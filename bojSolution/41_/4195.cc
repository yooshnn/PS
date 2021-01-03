#define DEBUG 0
#pragma GCC optimize("O3")
#define return_0 if (DEBUG) cout.flush(), system("pause"); else return 0;

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef pair<int, int> pii;

int par[200010], res[200010];

int search(int tar) {
	if (tar == par[tar]) return tar;
	return par[tar] = search(par[tar]);
}
void merge(int a, int b) {
	a = search(a), b = search(b);
	if (a != b) par[b] = a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int TEST; cin >> TEST; while (TEST--) {
        int cnt = 1;
        map<string, int> uid;
        int Q; cin >> Q;
        for (int i = 0; i <= 2*Q+2; ++i) par[i] = i, res[i] = 1;
        while (Q--) {
            string p1, p2; cin >> p1 >> p2;
            if (uid.find(p1) == uid.end()) uid[p1] = cnt++;
            if (uid.find(p2) == uid.end()) uid[p2] = cnt++;
            if (search(uid[p1]) != search(uid[p2])) {
                res[search(uid[p1])] += res[search(uid[p2])];
            }
            merge(search(uid[p1]), search(uid[p2]));
            cout << res[search(uid[p1])] << "\n";
        }

    }

    return_0;
}