#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            cout << i * m + j + 1;
            if (j != m - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}