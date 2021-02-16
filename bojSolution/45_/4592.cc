#include <bits/stdc++.h>
using namespace std;
#define sad cout.flush(), system("pause")

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

    int N;
	while (cin >> N) {
        if (N == 0) break;
        vector<int> v;
        int dup = -1;
        for (int i = 0, t; i < N; ++i) {
            cin >> t;
            if (t == dup) continue;
            dup = t;
            v.push_back(t);
        }
        for (int& x : v) cout << x << " ";
        cout << "$\n";
    }
}