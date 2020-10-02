#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, o;
    int cycle = 0;

    cin >> n;
    o = n;
    while (++cycle > 0) {
        n = (n % 10) * 10 + (((n / 10) + (n % 10)) % 10);
        if (n == o) break;
    }
    cout << cycle;

    return 0;
}