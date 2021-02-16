#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

    int TEST; cin >> TEST; while (TEST--) {
        int a, b, res = 0; cin >> a >> b;
        while (a < b) {
            a *= 2;
            res += 1;
        }
        cout << res << "\n";
    }
}