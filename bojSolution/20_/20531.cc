#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, Q;

int root[5010];
int search(int tar) {
    if (tar == root[tar]) return tar;
    return root[tar] = search(root[tar]);
}
void merge(int a, int b) {
    a = search(a), b = search(b);
    if (a == b) return; root[b] = a;
}

ll ans[5010][5010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ans[0][0] = 1;
    for (int i=1; i<=5000; ++i) { 
        ans[i][0] = (ans[i-1][i-1]) % MOD; 
        for (int j=1; j<=i; ++j) ans[i][j] = (ans[i-1][j-1] + ans[i][j-1]) % MOD; 
    } 

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) root[i] = i;
    int g = N;

    while (Q--) {
        int p, q; cin >> p >> q;
        if (search(p) != search(q)) {
            g -= 1;
            merge(p, q);
        }
        cout << ans[g][0] << "\n";
    }

}