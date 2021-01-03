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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    int s[N]; for (int& x : s) cin >> x;

    rope<int> seq; seq.push_back(1);
    for (int i = 1; i < N; ++i) {
        seq.insert(seq.size() - s[i], i+1);
    }

    for (auto it = seq.mutable_begin(); it != seq.mutable_end(); ++it) cout << *it << " ";

    return_0;
}