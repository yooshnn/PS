#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int sn(int n) {
    int ret = n;
    while (n != 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    bool isSn[10001] {false};

    for (int i = 1; i <= 10000; ++i) {
        if (sn(i) <= 10000) { isSn[sn(i)] = true; }
    }

    for (int i = 1; i <= 10000; ++i) {
       if (isSn[i] == false) { cout << i << "\n"; }
    }

    return 0;
}