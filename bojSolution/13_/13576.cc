#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int res = 1;
vector<int> Z, sfx;

void getZ(string s, vector<int>& ret) {
    int l = 0, r = 0, len = s.length();
    ret.resize(len, 0); ret[0] = len; sfx.push_back(ret[0]);
    for (int i = 1; i < len; ++i) {
        if (i > r) {
            l = r = i;
            while (r < len && s[r] == s[r - l]) r++;
            ret[i] = r - l;
            r--;
        }
        else {
            if (ret[i - l] <= r - i) {
                ret[i] = ret[i - l];
            }
            else {
                l = i;
                while (r < len && s[r] == s[r - l]) r++;
                ret[i] = r - l;
                r -= 1;
            }
        }
        if (ret[i] != 0) sfx.push_back(ret[i]);
        if (ret[i] + i == len) res++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string S; cin >> S;
    int len = S.length();
    getZ(S, Z); sort(sfx.begin(), sfx.end());

    cout << res << "\n";
    for (int i = len - 1; i >= 0; --i) {
        if (Z[i] + i != len) continue;
        int req = sfx.size() - (lower_bound(sfx.begin(), sfx.end(), Z[i]) - sfx.begin());
        cout << Z[i] << " " << req << "\n";
    }

    return 0;
}