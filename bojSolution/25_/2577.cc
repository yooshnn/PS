#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n = 1, temp, count, len, m;
    for (int i = 0; i < 3; ++i) {
        cin >> temp;
        n *= temp;
    }
    for (int i = 0; i < 10; ++i) {
        m = n;
        count = 0;
        len = to_string(n).length();
        for (int j = 1; j <= len; ++j) {
            if (m % 10 == i) count++;
            m /= 10;
        }
        cout << count << "\n";
    }

    return 0;
}