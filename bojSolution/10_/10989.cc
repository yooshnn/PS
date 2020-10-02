#include <iostream>
using namespace std;

int T, input;
unsigned short int a[10000]{ 0, };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> input;
        a[input - 1]++;
    }
    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < a[i]; j++) {
            cout << i + 1 << "\n";
        }
    }

    return 0;
}