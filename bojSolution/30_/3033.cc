#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
inline ll mod(ll n) { if (n >= 0) return n % MOD; return ((-n / MOD + 1) * MOD + n) % MOD; }

int L;
string src;

int rabinKarp(int len) {
    ll H = 0, power = 1;
    unordered_map<int, vector<int>> hashTable;
    for (int i = 0; i <= src.length() - len; ++i) {
        if (i == 0) {
            for (int j = 0; j < len; ++j) {
                H = mod(H + 1LL * src[len - 1 - j] * power);
                if (j < len - 1) power = mod(power * 127);
            }
        }
        else {
            H = mod(127 * (H - 1LL * src[i - 1] * power) + src[i + len - 1]);
        }

        if (hashTable[H].size() == 0) hashTable[H].push_back(i);
        else {
            for (int pos : hashTable[H]) {
                for (int p = 0; p < len; ++p) {
                    if (src[pos + p] != src[i + p]) break;
                    if (p == len - 1) return true;
                }
            }
            hashTable[H].push_back(i);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> L >> src;
    int lower = 0, upper = L, res = 0;
    while (lower <= upper) {
        int mid = (lower + upper) / 2;
        if (rabinKarp(mid)) {
            res = mid;
            lower = mid + 1;
        }
        else upper = mid - 1;
    }
    cout << res;

    return 0;
}