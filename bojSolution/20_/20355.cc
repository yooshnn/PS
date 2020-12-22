#include<bits/stdc++.h>
using namespace std;

bool next(string& s) {
    bool ret = 1;
    for (char& c : s) {
        c -= 'a';
        c = (c + 1) % 26;
        c += 'a';
        if (c == 'i') ret = 0;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;

    int res = 0;
    for (int i = 0; i < 26; ++i) {
        res += next(s);
    }
    if (res) cout << res;
    else cout << "impossible";
}