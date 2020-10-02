#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << " ";
        }
        for (int j = 2 * n - 2 * i - 1; j > 0; --j) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = n-2; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            cout << " ";
        }
        for (int j = 2 * n - 2 * i - 1; j > 0; --j) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}