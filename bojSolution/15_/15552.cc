#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int T, a, b;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> a >> b;
        cout << a + b << "\n";
    }
    return 0;
}