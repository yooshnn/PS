#include <bits/stdc++.h>
using namespace std; int TEST;

int n;
string s;
map<char, int> chars;
int cnt[26];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cin >> TEST;

    while (TEST--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (char c : s) {
                cnt[int(c - 'a')] += 1;
            }
        }
        bool isGood = true;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % n != 0) isGood = false;
            cnt[i] = 0;
        }
        cout << (isGood ? "YES" : "NO") << "\n";
    }

    return 0;
}