#include <iostream>
using namespace std;

int main() {
    int n, r = 99;
    
    cin >> n;

    if (n < 100) {
        cout << n;
    }
    else {
        for (int i = 100; i <= n; ++i) {
            if ((i / 100 - (i / 10) % 10) == ((i / 10) % 10 - i % 10)) r++;
        }
        cout << r;
    }

    return 0;
}