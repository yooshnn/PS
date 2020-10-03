#include <bits/stdc++.h>
using namespace std;

int n, res = 0;
vector<int> Z;

void getZ(string src) {
    int l = 0, r = 0, len = src.length();
    Z.resize(len);
    for (int i = 1; i < len; i++) {
        Z[i] = max(0, min(Z[i - l], r - i));
        while (src[i + Z[i]] && src[Z[i]] == src[i + Z[i]]) Z[i]++;
        if (i + Z[i] > r) l = i, r = i + Z[i];
        if (i >= len / 2 && i + Z[i] == len) res = max(res, Z[i]);
    }
    Z[0] = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; string s;
    cin >> n >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; ++i) s += s[n - i - 1];
    getZ(s);

    //for (int i : Z) cout << i << " ";

    cout << max(0, n - res);

    return 0;
}