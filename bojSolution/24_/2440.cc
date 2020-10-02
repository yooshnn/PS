#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = n; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}