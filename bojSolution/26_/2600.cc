#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int b1, b2, b3, k1, k2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> b1 >> b2 >> b3;
    for (int i = 0; i < 5; ++i) {
        cin >> k1 >> k2;
        vector<int> grundy(max(k1, k2) + 1, 0);
        for (int j = 1; j <= max(k1, k2); ++j) {
            set<int> next;
            if (j - b1 >= 0) next.insert(grundy[j - b1]);
            if (j - b2 >= 0) next.insert(grundy[j - b2]);
            if (j - b3 >= 0) next.insert(grundy[j - b3]);
            int tt = 0;
            while (next.find(tt) != next.end()) tt++;
            grundy[j] = tt;
        }
        cout << ((grundy[k1] ^ grundy[k2]) == 0 ? "B" : "A") << "\n";
    }
}