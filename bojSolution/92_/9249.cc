#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
using namespace std;

const int MOD = 1000000007, POW = 31;
inline ll mod(ll n) { if (n >= 0) return n % MOD; return ((-n / MOD + 1) * MOD + n) % MOD; }

string src, tar;

string rabinKarp(int len) {
    ll H = 0, power = 1;
    unordered_map<int, vector<int>> hashTable;
    for (int i = 0; i <= src.length() - len; ++i) {
        if (i == 0) {
            for (int j = 0; j < len; ++j) {
                H = mod(H + 1LL * src[len - 1 - j] * power);
                if (j < len - 1) power = mod(power * POW);
            }
        }
        else {
            H = mod(POW * (H - 1LL * src[i - 1] * power) + src[i + len - 1]);
        }
        hashTable[H].push_back(i);
        /*for (int pos : hashTable[H]) {
            if (src.substr(pos, len) != src.substr(i, len)) continue;
            return true; break;
        }*/
    }

    H = 0, power = 1;
    for (int i = 0; i <= tar.length() - len; ++i) {
        if (i == 0) {
            for (int j = 0; j < len; ++j) {
                H = mod(H + 1LL * tar[len - 1 - j] * power);
                if (j < len - 1) power = mod(power * POW);
            }
        }
        else {
            H = mod(POW * (H - 1LL * tar[i - 1] * power) + tar[i + len - 1]);
        }
        for (int pos : hashTable[H]) {
            if (src.substr(pos, len) == tar.substr(i, len)) return src.substr(pos, len);
        }
    }
    return "-1";
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int resLen; string res;

    cin >> src >> tar;
    int lower = 0, upper = min(src.length(), tar.length());
    while (lower <= upper) {
        int mid = (lower + upper) / 2;
        string req = rabinKarp(mid);
        if (req != "-1") {
            resLen = mid;
            res = req;
            lower = mid + 1;
        }
        else upper = mid - 1;
    }
    cout << resLen << "\n" << res;

	return 0;
}