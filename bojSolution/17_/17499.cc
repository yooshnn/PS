#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, Q, p = 0; cin >> N >> Q;
    vector<int> s(N); for (int& x : s) cin >> x;

    int oper, i, x; 
    while (Q--) {
        cin >> oper;
        if (oper == 1) {
            cin >> i >> x;
            i--;
            s[(p+i)%N] += x;
        }
        else if (oper == 2) {
            cin >> i;
            p = (N+p-i) % N;
        }
        else {
            cin >> i;
            p = (N+p+i) % N;
        }

    }

    for (int i = p; i < N; ++i) cout << s[i] << " ";
    for (int i = 0; i < p; ++i) cout << s[i] << " ";

}